#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200010
#define M 1000010
#define L 18

ll Limit;

struct plan {
    int l, r, c, p;
    bool operator < (const plan &P) const {
        return p < P.p;
    }
    void in() {
        scanf("%d%d%d%d", &l, &r, &c, &p);
    }
} q[N];

struct Fenwick {
    ll f[N], g[N];
    void update(int x, int c, int p) {
        for(; x < N; x += x & -x) {
            f[x] += c;
            g[x] += 1ll * c * p;
        }
    }
    ll calc() {
        int x = 0;
        ll y = 0, z = 0;
        for(int i = L - 1; i >= 0; i --) {
            int xx = x + (1 << i);
            if(xx >= N || y + f[xx] > Limit) continue;
            x = xx;
            y += f[x];
            z += g[x];
        }
        if(x == N - 1) return z;
        return z + (Limit - y) * q[x+1].p;
    }
} F;

vector <int> I[M], D[M];

int main() {
    int n, m;
    scanf("%d%I64d%d", &n, &Limit, &m);
    for(int i = 1; i <= m; i ++) q[i].in();
    sort(q + 1, q + m + 1);
    for(int i = 1; i <= m; i ++) {
        I[q[i].l].push_back(i);
        D[q[i].r+1].push_back(i);
    }
    ll ans = 0, cur = 0;
    for(int i = 1; i <= n; i ++) {
        if(I[i].size() == 0 && D[i].size() == 0) {
            ans += cur;
            continue;
        }
        for(int j = 0; j < I[i].size(); j ++) {
            int k = I[i][j];
            F.update(k, q[k].c, q[k].p);
        }
        for(int j = 0; j < D[i].size(); j ++) {
            int k = D[i][j];
            F.update(k, -q[k].c, q[k].p);
        }
        cur = F.calc();
        ans += cur;
    }
    printf("%I64d\n", ans);
}