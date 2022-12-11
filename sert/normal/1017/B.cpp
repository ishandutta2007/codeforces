#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    ll n0 = 0, n1 = 0, a01 = 0, a11 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') n0++;
        if (s[i] == '1') n1++;
        if (s[i] == '0' && t[i] == '1') a01++;
        if (s[i] == '1' && t[i] == '1') a11++;
    }
    cout << n0 * n1 - a01 * a11 << "\n";
}

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	solve();
#endif

	//int t; scanf("%d", &t); while (t--)
	//int t; cin >> t; while (t--)
	solve();
}