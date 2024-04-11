#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int main() {
	string s, t; cin >> s >> t;
	int N = s.length(), M = t.length();
	vector<int> a(27);
	rep(i, N) if (s[i] == '?') a[26]++; else a[s[i] - 'a']++;
	vector<int> b(26);
	rep(j, M) b[t[j] - 'a']++;
	vector<int> c(26);
	for (int t = 0; ; t++) {
		vector<int> _c(26);
		rep(k, 26) _c[k] = max(0, t * b[k] - a[k]);
		int sum = 0;
		rep(k, 26) sum += _c[k];
		if (sum > a[26]) break;
		c = _c;
	}
	rep(k, 26) for (int i = 0; c[k]; i++) if (s[i] == '?') {
		s[i] = 'a' + k;
		c[k]--;
	}
	rep(i, N) if (s[i] == '?') s[i] = 'a';
	cout << s << endl;
}