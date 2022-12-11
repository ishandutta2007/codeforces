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
    int n, m;
    cin >> n >> m;
    cout << (n > 28 ? m : m % (1 << n)) << "\n";
}

int main() {
    init();
	//solve();
	//solve();
	solve();
    return 0;
}