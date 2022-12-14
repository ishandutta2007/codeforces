//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

int a[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read(), res = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		res += a[i];
		if (res >= m)
			return cout << n - i, 0;
	}
	
}