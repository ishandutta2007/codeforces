//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)


int read() { int x; cin >> x; return x; }

int n, q;
map<pair<char, char>, char> mp;

int go(int step, string s = "") {
	if (!step) {
		char cur = s[0];
		for (int i = 1; i < n; ++i)
			if (mp.find({cur, s[i]}) != mp.end())
				cur = mp[{cur, s[i]}];
			else
				return 0;
		if (cur != 'a')
			return 0;
		return 1;
	}
	int res = 0;
	for (int nxt = 'a'; nxt <= 'f'; ++nxt) {
		string t = s;
		t += nxt;
		res += go(step - 1, t);
	}
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), q = read();
	rep(i, q) {
		string a, b;
		cin >> a >> b;
		mp[{a[0], a[1]}] = b[0];
	}
	cout << go(n);
}