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
    cin >> n;
    int a, b, c, d, s, cr, ans = 1;
    cin >> a >> b >> c >> d; s = a + b + c + d;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c >> d;
        cr = a + b + c + d;
        if (cr > s) ans++;
    }
    cout << ans << "\n";
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