#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e5 + 34;
const int DEF = 0;

inline int getLvl(ll v) {
    ll ans = 0;
    while (v > 1) {
        v /= 2;
        ans++;
    }
    return ans;
}

void printPath(ll v, const vector<ll> &sh) {
    ll lv = getLvl(v);
    for (ll i = lv; i > 0; i--) {
        printf("%I64d ", v);
        ll sz = (1ll << i);
        ll kk = ((v + sh[i] + sz) & (sz - 1));
        if (i > 1)
            v = ((kk / 2 - sh[i - 1] + sz / 2) & (sz / 2 - 1)) + sz / 2;
    }
    cout << "1\n";
}

const ll MX = 62;
void solve() {
    vector<ll> sh(MX, 0);
    int m;
    scanf("%d", &m);
    while (m--) {
        int t;
        ll x, sf;
        scanf("%d", &t);
        if (t == 3) {
            scanf("%I64d", &x);
            printPath(x, sh);
        } else {
            scanf("%I64d%I64d", &x, &sf);
            ll lv = getLvl(x);
            ll sz = (1ll << lv);
            sf = (sf % sz + sz) % sz;
            for (ll i = lv; i < MX; i++) {
                ll sz = (1ll << i);
                sh[i] += sf;
                if (sh[i] >= sz) sh[i] -= sz;
                sf *= 2;
                if (t == 1) break;
            }
        }
    }
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}