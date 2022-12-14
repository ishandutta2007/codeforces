//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e6 + 6;

int read() { int x; cin >> x; return x; }


int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	set<int> st;
	int n, m; cin >> n >> m;
	for (int i = 1; i < N; ++i)
		st.insert(i * 2), st.insert(i * 3);
	int six = 0;
	for (int x : st) {
		if (x % 6 == 0)
			six++;
		if (x % 3 == 0 && x % 2 != 0 && m)
			m--;
		if (x % 2 == 0 && x % 3 != 0 && n)
			n--;
		if (m + n <= six) {
			cout << x;
			return 0;
		}
	}
}