//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long int49;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

pii a[N];
int ans[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	for (int i = 0; i < n; ++i) {
		int x = read(), y = read();
		a[i] = {x, y};
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		int x = a[i].first, d = a[i].second;
		int pos = lower_bound(a, a + n, make_pair(x - d, -1)) - a;
		ans[i] = i - pos + (pos? ans[pos - 1]: 0);	
	}
	int best = n;
	for (int i = 0; i < n; ++i)
		smin(best, ans[i] + n - i - 1);
	cout << best << endl;
}