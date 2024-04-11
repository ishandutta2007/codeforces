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

int kek(char ch) {
    if (ch == 'a' || ch == 'o' || ch == 'i' || ch == 'u' || ch == 'e') return 1;
    if ('0' <= ch && ch <= '9' && (ch - '0') % 2 == 1) return 1;
    return 0;
}

void solve() {
    int ans = 0;
    string s;
    cin >> s;
    for (char ch: s) ans += kek(ch);
    cout << ans << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}