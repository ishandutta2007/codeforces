#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e7 + 34;
const ll md = (ll)1e9 + 7;

bool u[N];
int prim[N / 4], plen;
int n;
int valid = 0;

ll num[N];
ll sf[N];
int nxp[N];
int rs[N];

inline int go(int x) {
    int xx = x;
    int p[10], m = 0;

    for (int i = 0; prim[i] * prim[i] <= x; i++) {
        if (x % prim[i]) continue;
        p[m++] = prim[i];
        while (x % prim[i] == 0)
            x /= prim[i];
    }
    if (x > 1)
        p[m++] = x;


    if (m == 1 && p[0] * 2 > n)
        return 0;

    num[p[0]]++;

    int res = 0;

    if (m == 1)
        res = n / p[0];
    else {
        int y = 1;
        for (int i = 0; i < m - 1; i++)
            y *= p[i];
        res = n / p[m - 1] + rs[y];
        y = p[m - 1];
        for (int msk = 1; msk < (1 << (m - 1)); msk++) {
            if (msk & 1)
                y *= p[0];
            else {
                y = p[m - 1];
                for (int i = 0; i < m - 1; i++)
                    if (msk & (1 << i))
                        y *= p[i];
            }
            if (__builtin_popcount(msk) % 2)
                res -= n / y;
            else
                res += n / y;
        }
    }

    rs[xx] = res;

    //cerr << xx << " " << m << " ";

    /*for (int msk = 1; msk < (1 << m); msk++) {
        int y = 1;
        for (int i = 0; i < m; i++)
            if (msk & (1 << i))
                y *= p[i];
        if (__builtin_popcount(msk) % 2)
            res += n / y;
        else
            res -= n / y;
    }*/
    res--;
    //cerr << res << " ";
    //cerr << (valid - res - 1) * 2 + res << "\n";

    return (valid - res - 1) * 2 + res;
}

int main() {
    init();

    u[0] = u[1] = true;
    for (int i = 2; i < N; i++) {
        if (u[i]) continue;

        prim[plen++] = i;

        for (int j = i * 2; j < N; j += i) {
            u[j] = true;
        }
    }

    cin >> n;

    int nx = plen - 1;
    for (int i = 0; i < plen - 1; i++) {
        nx = max(nx, i + 1);
        while (nx - 1 > i && (ll)prim[i] * (ll)prim[nx - 1] > n)
            nx--;
        nxp[prim[i]] = prim[nx];
    }


    valid = n - 1;
    for (auto p: prim) {
        if (p <= n && p * 2 > n)
            valid--;
    }

    //cerr << "valid = " << valid << "\n";

    ll ans = 0;
    for (int i = 2; i <= n; i++)
        ans += go(i);

    ans /= 2;

    sf[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        sf[i] = sf[i + 1] + num[i];

    ll cur = n - 1;
    ll lp = -1;

    for (int i = 0; i < plen; i++) {
        ll p = prim[i];
        if (p * 2 > n) continue;

        while (cur > 0 && p * (cur - 1) > n) {
            cur--;
            if (!u[cur]) lp = cur;
        }

        if (lp > p) {
            ans += num[p] * sf[lp];
            //cerr << p << " " << lp << " " << num[p] << " " << sf[lp] << "\n";
        } else {
            //continue;
            //cerr << p << " " << nxp[p] << " " << num[p] << " " << sf[nxp[p]] << " kk\n";
            ans += num[p] * sf[nxp[p]];
        }
    }

    cout << ans;

    return 0;
}