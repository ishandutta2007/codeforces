#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n , m , pre[N] , mcnt;
struct edge {
    int x;
    LL w;
    int next;
} e[N << 1];
bool ee[N];
LL res , d[N];
bool vis[N];

vector<LL> V , W;
void dfs(int x , int fa) {
    vis[x] = 1;
    W.push_back(d[x]);
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!vis[y]) {
            d[y] = d[x] ^ e[i].w;
            dfs(y , x);
        } else if (y != fa && !ee[i >> 1]) {
            ee[i >> 1] = 1;
            V.push_back(d[x] ^ d[y] ^ e[i].w);
        }
    }
}

void work(int root) {
    V.clear();
    W.clear();
    dfs(root , 0);
    int Rank = 0 , m = V.size();
    for (int k = 0 ; k < 60 ; ++ k) {
        int x = Rank;
        while (x < m && (~V[x] >> k & 1)) {
            ++ x;
        }
        if (x >= m) continue;
        swap(V[x] , V[Rank]);
        for (int i = 0 ; i < m ; ++ i) {
            if (i != Rank && (V[i] >> k & 1)) {
                V[i] ^= V[Rank];
            }
        }
        ++ Rank;
    }
    for (int k = 0 ; k < 60 ; ++ k) {
        int cnt[2] = {};
        for (int i = 0 ; i < Rank ; ++ i) {
            cnt[V[i] >> k & 1] ++;
        }
        LL w[2] = {};
        if (cnt[1]) {
            w[1] = (1LL << Rank - 1) % Q;
        } else {
            w[1] = 0;
        }
        w[0] = ((1LL << Rank) - w[1] + Q) % Q;
        int u[2] = {};
        int ret = 0;
        for (auto &v : W) {
            int c = v >> k & 1;
            for (int a = 0 ; a < 2 ; ++ a) {
                for (int b = 0 ; b < 2 ; ++ b) {
                    if (a ^ b ^ c) {
                        ret += (LL)w[a] * u[b] % Q;
                        ret %= Q;
                    }
                }
            }
            u[c] ++;
        }
        res += (1LL << k) % Q * ret % Q;
        res %= Q;
    }



}

int main() {
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i <= m ; ++ i) {
        int x , y; LL w;
        scanf("%d%d%lld" , &x , &y , &w);
        e[mcnt] = (edge) {y , w , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , w , pre[y]} , pre[y] = mcnt ++;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) {
            work(i);
        }
    }
    cout << res << endl;
}