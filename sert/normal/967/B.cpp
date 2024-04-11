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

void solve() {
    ll n, a, b, x;
    cin >> n >> a >> b >> x;
    vector<ll> v(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll sum = x;
    for (int i = 0; i < n - 1; i++) sum += v[i];
    for (int i = 0; i < n - 1; i++) {
        if (b * sum <= a * x) {
            cout << i << "\n";
            return;
        }
        sum -= v[i];
    }
    cout << n - 1 << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
	//solve();
    return 0;
}