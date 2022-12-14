//In the name of God
// ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }



const int N = 1e5 + 5;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 9;

int read() { int x; cin >> x; return x; }

pair<pii, int> p[N];
pii q[N << 2];
int h, t;
pii ans[N];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	for (int i = 0; i < m; ++i)
		p[i] = {{read(), 1 - read()}, i};
	sort(p, p + m);
	int cnt = 0;
	for (int _ = 0; _ < m; ++_) {
		int i = p[_].second, te = p[_].first.second;
//		cout << i << ' ' << te << endl;
		if (!te) {
			ans[i] = {0, ++cnt};	
			if (t < N) {
				for (int j = 1; j <= cnt - 1; ++j)
					q[t++] = {j, cnt};
			}
		} else {
			if (h == t) {
				cout << -1;
				return 0;	
			}
			ans[i] = q[h++];
		}
		
	}
//	if (cnt >= n) {
//		cout << -1;
//		return 0;
//	}
	for (int i = 0; i < m; ++i)
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
	
}