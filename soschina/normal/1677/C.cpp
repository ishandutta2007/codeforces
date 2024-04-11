#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 1;

int t, n;
struct node{
    int a, b;
    node(){}
    node(int a, int b) : a(a), b(b){}
    bool operator<(const node &r) const{
        return a < r.a;
    }
} nd[N];
int sum, oddrings;
bool vis[N];

void dfs(int i, int cnt){
    if(vis[i]){
        sum += cnt / 2;
        return;
    }
    vis[i] = true;
    dfs(nd[i].b, cnt + 1);
}

int main(){
    scanf("%d", &t);
    while(t--){
        sum = 0;
        oddrings = 0;
        memset(vis + 1, 0, sizeof(bool) * n);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &nd[i].a);
        for (int i = 1; i <= n; i++)
            scanf("%d", &nd[i].b);
        sort(nd + 1, nd + 1 + n);
        for (int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i, 0);
        long long ans = 0;
        for (int i = 1; i <= sum; i++)
            ans += 2 * (n - i - i + 1);
        printf("%lld\n", ans);
    }
    return 0;
}