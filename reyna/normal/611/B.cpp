//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 62;

int read() { int x; cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll l, r;
	cin >> l >> r;
	int res = 0;
	for (int len = 2; len < N; ++len) {
		ll x = (1LL << len) - 1;
		for (int lift = 0; lift < len - 1; ++lift) {
			if (x - (1LL << lift) <= r && x - (1LL << lift) >= l)
				res++; 
		}
	}
	cout << res << endl;
}