#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll SIG = 26;

string s;
int q, f[MAXN], t[MAXN][SIG];

int add_char(int k, char c) {
	if (c == s[k + 1]) return k + 1;
	k = f[k];
	return t[k][c - 'a'];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int n = s.size();
	s = "." + s;

	for (int i = 1; i <= n; i++) {
		for (char c = 'a'; c <= 'z'; c++)
			t[i - 1][c - 'a'] = max(int(c == s[1]), add_char(i - 1, c));
		
		if (i > 1) f[i] = add_char(f[i - 1], s[i]);
	}

	int q;
	cin >> q;
	while (q--) {
		string tmp;
		cin >> tmp;

		int k = f[n];
		for (char c : tmp) s.push_back(c);

		int m = s.size() - 1;
		for (int i = n + 1; i <= m; i++) {
			f[i] = -1;
			while (k >= n) {
				if (s[k + 1] == s[i]) {
					k++;
					f[i] = k;
					break;
				}

				k = f[k];
			}
			
			if (f[i] < 0) {
				k = t[k][s[i] - 'a'];
				f[i] = k;
			}

			cout  << f[i] << sep;
		}
		
		for (char c : tmp)
			s.pop_back();
		cout << endl;
	}
	return 0;
}