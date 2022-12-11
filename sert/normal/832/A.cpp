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

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << (n % (2 * k) >= k ? "YES" : "NO") << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}