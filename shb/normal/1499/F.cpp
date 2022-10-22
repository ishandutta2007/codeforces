#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
vector<int>e[5010];
int sz[5010];
int g[5010], h[5010], f[5010][5010], S[5010];
const int MOD = 998244353;

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void dfs(int x,int fa) {
    sz[x] = 1;
    f[x][0] = 1;
    for (auto &t : e[x]) {
        if (t != fa) {
            dfs(t, x);
            //printf("merge %d %d\n",x,t);
            for (int j = 0; j <= K; j++) h[j] = 0;
            // this subtree
            for (int j = 0; j <= sz[t]; j++) {
                int this_f = (j == 0 ? S[t] : f[t][j - 1]);
                // all last subtrees
                for (int k = 0; k <= sz[x]; k++) {
                    if (j + k > K) break;
                    int last_f = f[x][k];
                    upd(h[max(k, j)], 1LL * this_f * last_f % MOD);
                }
            }
            for (int j = 0; j <= K; j++) {
                f[x][j] = h[j];
            }
            sz[x] += sz[t];
            /*
             for (int i=0;i<=K;i++) {
                printf("tmp:f[%d][%d] = %d\n",x,i,f[x][i]);
            } 
            */ 
        }
    }
    S[x] = 0;
    for (int i=0;i<=K;i++) {
        upd(S[x], f[x][i]);
    }
    /*
    for (int i=0;i<=K;i++) {
        printf("f[%d][%d] = %d\n",x,i,f[x][i]);
    } 
    */ 
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i=0;i<=K;i++) {
        upd(ans, f[1][i]);
    }
    printf("%d\n",ans);
}