#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e5 + 1;

int t, n, fa[N], cnt, stk[N], top;
bool isleaf[N], vis[N] = {true};

int main(){
    scanf("%d", &t);
    while(t--){
        memset(vis + 1, 0, sizeof(bool) * n);
        scanf("%d", &n);
        memset(isleaf + 1, 1, sizeof(bool) * n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &fa[i]);
            if(fa[i] != i)
                isleaf[fa[i]] = false;
        }
        cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += isleaf[i];
        printf("%d\n", cnt);
        for(int i = 1; i <= n; i++) if(isleaf[i]){
            top = 0;
            int u = i;
            while(!vis[u]){
                stk[++top] = u;
                vis[u] = true;
                u = fa[u];
            }
            printf("%d\n", top);
            while(top)
                printf("%d ", stk[top--]);
            putchar('\n');
        }
    }
    return 0;
}