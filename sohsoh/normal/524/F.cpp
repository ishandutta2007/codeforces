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

constexpr int MAXN = 2e6 + 5;

pair<pair<int, int>, int> x[MAXN];
int n, rnk[MAXN];

inline void set_rank() {
	sort(x, x + n, [] (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.X < b.X;
	});
	for (int i = 1, cur = 0; i < n; i++)
		rnk[x[i].second] = cur += x[i].first != x[i - 1].first;
}

inline void build(string s) {
	n = s.size();
	for (int i = 0; i < n; i++)
		x[i] = {{s[i], 0}, i};

	for (int i = n; i < MAXN; i++)
		x[i] = {{int('(') + 1, 0}, i};
	set_rank();

	for (int i = 0; MAXN >> i; i++) {
		for (int j = 0; j < MAXN; j++)
			x[j] = {{rnk[j], j + (1 << i) < n? rnk[j + (1 << i)]: -1}, j};
		set_rank();
	}
}

int ind[MAXN], pref[MAXN], pref_mn[MAXN], suff[MAXN], suff_mn[MAXN];
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	build(s + s);
	
	n = s.size();
	s = "." + s;

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
		pref_mn[i] = min(pref_mn[i - 1], pref[i]);
	}

	int bal = max(0, -pref[n]);
	pll ans = {MAXN, 1};
	for (int i = n; i > 0; i--) {
		suff[i] = suff[i + 1] + (s[i] == '(' ? 1 : -1);
		suff_mn[i] = min(suff_mn[i + 1] + (s[i] == '(' ? 1 : -1), 0);

		if (min(suff_mn[i], suff[i] + pref_mn[i - 1]) + bal >= 0)
			ans = min(ans, {rnk[i - 1], i});
	}

	while (bal--)
		cout << '(';

	for (int i = ans.Y; i <= n; i++)
		cout << s[i];
	for (int i = 1; i < ans.Y; i++)
		cout << s[i];

	while (pref[n]-- > 0)
		cout << ')';
	cout << endl;
	return 0;
}