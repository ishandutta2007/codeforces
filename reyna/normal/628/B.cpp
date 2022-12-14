//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 3e5 + 5;

int read() { int x; cin >> x; return x; }

int a[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
		if (a[i] % 4 == 0)
			res++;	
	}
	for (int i = 1; i < n; ++i) {
		int x = 10 * a[i - 1] + a[i];
		if (x % 4 == 0)
			res += i;
	}
	cout << res << endl;
}