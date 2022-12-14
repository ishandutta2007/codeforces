//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 0;

int read() { int x; cin >> x; return x; }

int cnt[1010];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	rep(i, n) {
		int x = read();
		cnt[x]++;
	}
	rep(i, 1009) if (i != 0) {
		if (cnt[i] && cnt[i - 1] && cnt[i + 1]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}