#include <cstdio>
#include <cstring>
using namespace std;
const int N = 4001;

int t, n, ind[N], fa[N], b[N], w[N];
char s[N + 1];

int ans;
void dfs(int i){
    ind[i] = -1;
    if(b[i] == w[i])
        ans++;
    b[fa[i]] += b[i];
    w[fa[i]] += w[i];
    ind[fa[i]]--;
    if(!ind[fa[i]])
        dfs(fa[i]);
}

int main(){
    ind[0] = 0x7fffffff;
    scanf("%d", &t);
    while(t--){
        memset(b + 1, 0, sizeof(int) * n);
        memset(w + 1, 0, sizeof(int) * n);
        memset(ind + 1, 0, sizeof(int) * n);
        ans = 0;
        scanf("%d", &n);
        for (int i = 2; i <= n; i++){
            scanf("%d", &fa[i]);
            ind[fa[i]]++;
        }
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++){
            if(s[i] == 'B') b[i]++;
            else
                w[i]++;
        }
        for (int i = 1; i <= n; i++){
            if (ind[i] == 0)
                dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}