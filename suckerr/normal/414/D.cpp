#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

int dep[N], cnt[N], n, k, cash;
int q[N], tot;
vector<int> e[N];

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    q[++tot] = dep[x];
    for(int i = 0; i < (int)e[x].size(); i++) {
        int y = e[x][i];
        if (y == fa)
            continue;
        dfs(y, x);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &cash);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    sort(q + 1, q + n + 1);
    long long c = 0;
    int ans = 0;
    for(int i = 2, l = 2, j; i <= n; i = j) {
        c += (i - l);
        for(j = i; j <= n && q[j] == q[i]; ++j);
        while(c > cash || (j - l) > k) {
            c -= (q[i] - q[l]);
            l++;
        }
        ans = max(ans, j - l);
    }
    printf("%d\n", ans);
    return 0;
}