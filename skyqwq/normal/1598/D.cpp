// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long
using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

typedef pair<int, int> PII;

int n, c1[N], c2[N], t;

PII e[N], d[N];

map<int, int> M1, M2;

LL cnt;

void inline ins(int x) {
    M1[x]++;
    cnt += M2[x];
}

void inline del(int x) {
    M2[x]--;
    cnt -= M1[x];
}
 
signed main() {
    int T; read(T);
    while (T--) {
        read(n);
        LL ans = 0; t = 0; 
        M1.clear(), M2.clear(); 
        cnt = 0;
        for (int i = 1; i <= n; i++) read(e[i].fi), read(e[i].se), c1[e[i].fi]++, c2[e[i].se]++;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            ans += c1[i] * s * (n - c1[i] - s);
            s += c1[i];
        }
        s = 0;
        for (int i = 1; i <= n; i++) {
            ans += c2[i] * s * (n - c2[i] - s);
            s += c2[i];
        }
        sort(e + 1, e + 1 + n);
        for (int i = 1; i <= n; i++) {
            int j = i;
            while (j < n && e[j + 1].fi == e[i].fi) j++;
            d[++t] = mp(i, j);
            i = j; 
        }

        for (int i = d[1].se + 1; i <= n; i++)
            M2[e[i].se]++;
        for (int i = 1; i <= t; i++) {
            int L = d[i].fi, R = d[i].se;
            for (int j = L; j <= R; j++) {
                LL gx = (L - 1 - M1[e[j].se]) * (n - R - M2[e[j].se]);
                gx -= cnt;
                gx += M1[e[j].se] * M2[e[j].se];
                ans -= gx;
            }
            for (int j = L; j <= R; j++) ins(e[j].se);
            if (i < t) for (int j = d[i + 1].fi; j <= d[i + 1].se; j++) del(e[j].se);
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++) c1[i] = c2[i] = 0;
    }
    return 0;
}