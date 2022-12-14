//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 0;

int read() { int x; cin >> x; return x; }

vector<int> v;

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read();
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		if (x)
			v.push_back(i);
	}
	long long res = 1;
	if (v.size() == 0)
		res = 0;
	for (int i = 1; i < (int) v.size(); ++i) {
		int cur = v[i], prv = v[i - 1];
		res *= (v[i] - v[i - 1]);
	}
	cout << res << endl;
}