//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 0;

int read() { int x; cin >> x; return x; }




int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; string s;
	cin >> n >> s;
	int res = 0;
	for (int l = 0; l < n; ++l)
		for (int r = l + 1; r <= n; ++r) {
			int u = 0, v = 0;
			for (int x = l; x < r; ++x) {
				if (s[x] == 'U')
					u--;
				if (s[x] == 'D')
					u++;
				if (s[x] == 'R')
					v++;
				if (s[x] == 'L')
					v--;
			}
			if (!v && !u)
				res++;
		}
	cout << res;
}