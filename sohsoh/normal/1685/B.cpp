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

int a, b, c, d, t;
string s;
vector<int> A[2];

inline bool dojob(int ind, int x) {
	sort(all(A[ind]), greater<int>());
	sort(all(A[ind ^ 1]));

	while (x && !A[ind].empty()) {
		int k = A[ind].back();
		A[ind].pop_back();

		int q = min(k, x);
		k -= q;
		x -= q;

		if (k) t += k - 1;
	}

	if (x <= 0) return true;
	int k = min(t, x);
	t -= k;
	x -= k;

	if (x <= 0) return true;

	while (x && !A[ind ^ 1].empty()) {
		int k = A[ind ^ 1].back();
		A[ind ^ 1].pop_back();

		k--;
		int q = min(k, x);
		x -= q;
		k -= q;

		if (k) t += k;
	}

	if (x <= 0) return true;
	return false;
}

inline int solve() {
	t = 0;
	A[0].clear();
	A[1].clear();

	cin >> a >> b >> c >> d >> s;
	if (a + c + d != count(all(s), 'A') || b + c + d != count(all(s), 'B')) 
		return cout << "NO" << endl, 0;

	int len = 0, f = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		if (i == 0 || s[i] == s[i - 1]) {
			if (i) {
				if (len % 2 == 1) t += len / 2;
				else A[f].push_back(len / 2);			
			}

			len = 0;
			f = (s[i] == 'B');
		}

		len++;
	}


	if (len % 2 == 1) t += len / 2;
	else A[f].push_back(len / 2);			

	if (dojob(0, c) && dojob(1, d)) return cout << "YES" << endl, 0;
	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}