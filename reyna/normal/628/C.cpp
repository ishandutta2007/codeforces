//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 5;

int read() { int x; cin >> x; return x; }

int res[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		int best = max(s[i] - 'a', 'z' - s[i]), ch = (s[i] - 'a' == best? 'a': 'z');
		if (best <= k) {
			k -= best;
			res[i] = ch;
		} else {
			for (int j = 'a'; j <= 'z'; ++j) if (abs(j - s[i]) == k) {
				res[i] = j;
				k = 0;
				break;
			}
		}
	}
	if (k != 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		cout << char(res[i]);
}