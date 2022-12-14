#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200010
#define L 18

struct Fenwick {
    int n;
    ll f[N];
    int g[N];
    void update(int x, int v) {
        for(; x <= n; x += x & -x) f[x] += v, g[x] ++;
    }
    int calc(ll v) {
        int x = 0, z = 0;
        ll y = 0;
        for(int i = L - 1; i >= 0; i --) {
            int xx = x + (1 << i);
            if(xx > n || y + f[xx] > v) continue;
            x = xx;
            y += f[x];
            z += g[x];
        }
        return z;
    }
    ll sum(int v) {
        int x = 0, y = 0;
        ll z = 0;
        for(int i = L - 1; i >= 0; i --) {
            int xx = x + (1 << i);
            if(xx > n || y + g[xx] > v) continue;
            x = xx;
            y += g[x];
            z += f[x];
        }
        return z;
    }
    void init() {
        for(int i = 1; i <= n; i ++) f[i] = 0, g[i] = 0;
    }
} F;

pair <int, int> p[N];

int main() {
    int t, n, m;
    ll T;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d%I64d", &n, &m, &T);
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &p[i].first);
            p[i].second = i;
        }
        sort(p + 1, p + n + 1);
        F.n = n;
        int mx = 0, d = 1;
        for(int i = 1, j = 1; i <= n; i = j) {
            while(j <= n && p[i].first == p[j].first) j ++;
            for(int k = i; k < j; k ++) F.update(p[k].second, p[k].first);
            int cnt = F.calc(T / 2);
            cnt /= m, cnt *= m;
            ll A = F.sum(cnt);
            int nxt = F.calc(T - A);
            nxt = min(nxt, cnt + m);
            if(nxt > mx) mx = nxt, d = p[i].first;
        }
        printf("%d %d\n", mx, d);
        F.init();
    }
}