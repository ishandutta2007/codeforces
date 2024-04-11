#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1111111;

vector<pair<int, int> > q[N];
int stack[N], top = 0;
char buf[N];
int ans[N], h[N], n;

int lowbit(int x) {
    return (x & (-x));
}

int ask(int pos) {
    int res = 0;
    for(int i = pos; i; i -= lowbit(i))
        res += h[i];
    return res;
}

void ins(int pos) {
    for(int i = pos; i <= n; i += lowbit(i))
        h[i]++;
}

int main() {
    scanf("%s", buf + 1);
    n = strlen(buf + 1);
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        q[l].push_back(make_pair(r, i));
    }
    
    for(int i = n; i >= 1; i--) {
        if (buf[i] == ')') {
            stack[++top] = i;
        } else {
            if (top) {
                ins(stack[top]);
                top--;
            }
        }
        for(int j = 0; j < (int)q[i].size(); j++) {
            ans[q[i][j].second] = ask(q[i][j].first);
        }
    }
    for(int i = 1; i <= m; i++) {
        printf("%d\n", ans[i] * 2);
    }
    return 0;
}