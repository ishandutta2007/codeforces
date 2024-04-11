#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;

struct node{
    int a, b, c;
    bool operator<(const node &r) const{
        return a < r.a;
    }
}nd[N];

int t, n, cnt;
bool vis[N];

void dfs(int i, int k){
    if(vis[i]){
        cnt += k;
        return;
    }
    vis[i] = true;
    if(nd[i].c || nd[i].a == nd[i].b)
        k = 0;
    dfs(nd[i].b, k);
}

int main(){
    scanf("%d", &t);
    while(t--){
        cnt = 0;
        memset(vis + 1, 0, sizeof(bool) * n);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &nd[i].a);
        }
        for (int i = 1; i <= n; i++){
            scanf("%d", &nd[i].b);
        }
        for (int i = 1; i <= n; i++){
            scanf("%d", &nd[i].c);
        }
        sort(nd + 1, nd + 1 + n);
        for (int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i, 1);
        int ans = 1;
        while(cnt--){
            ans = (ans + ans) % 1000000007;
        }
        printf("%d\n", ans);
    }
    return 0;
}