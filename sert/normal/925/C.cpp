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
const int N = (int)1e6 + 34;
const int H = 60;

int getHighBit(ll x) {
    for (ll b = H; b >= 0; b--) {
        if (x & (1ll << b)) return b;
    }
    exit(11);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<vector<ll>> es(H);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%I64d", &x);
        es[getHighBit(x)].push_back(x);
    }

    vector<ll> cur;
    for (ll b = H - 1; b >= 0; b--) {
        vector<ll> nw;
        int ps = 0;
        int sz = es[b].size();
        for (int i = 0; i < (int)cur.size(); i++) {
            if (ps < sz && (cur[i] & (1ll << b))) {
                nw.push_back(es[b][ps++]);
            }
            nw.push_back(cur[i]);
        }
        if (ps < sz) {
            nw.push_back(es[b][ps++]);
        }
        if (ps < sz) {
            cout << "No\n";
            return;
        }
        cur = nw;
    }
    cout << "Yes\n";
    for (int i = 0; i < (int)cur.size(); i++) {
        cout << cur[i] << " ";
    }
    cout << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
	//solve();
    return 0;
}