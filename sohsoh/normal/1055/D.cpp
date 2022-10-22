// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 3e3 + 10;

int L[MAXN], R[MAXN], n, F[MAXN * 2];
string S[MAXN], T[MAXN];

inline bool check(int ind) {
	char c = '-', c2 = '-';
	for (int i = 1; i <= n; i++) {
		if (R[i] >= 0) {
			int j = L[i] + ind;
			if (j < 0 || j >= S[i].size()) return false;
			
			if (c == '-') c = S[i][j], c2 = T[i][j];
			else if (c != S[i][j] || c2 != T[i][j]) return false;
		}
	}

	return true;
}

inline string rep(string s, string a, string b) {
	string c = a + "$" + s;
	int k = 0;
	memset(F, 0, sizeof F);

	for (int i = 1; i < c.size(); i++) {
		while (k && c[k] != c[i])
			k = F[k - 1];
		k += (c[i] == c[k]);
		F[i] = k;

		if (k >= a.size()) {
			int ind = i - a.size() - 1, j = 0;
			for (int i = ind - a.size() + 1; i <= ind; i++)
				s[i] = b[j], j++;	
			return s;
		}
	}

	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> S[i];
	for (int i = 1; i <= n; i++) cin >> T[i];

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		L[i] = MAXN + 1, R[i] = -1;
		for (int j = 0; j < S[i].size(); j++) {
			if (S[i][j] != T[i][j]) {
				L[i] = min(L[i], j);
				R[i] = j;
			}
		}

		mx = max(mx, R[i] - L[i] + 1);
	}

	for (int i = 0; i < mx; i++)
		if (!check(i))
			return cout << "NO" << endl, 0;

	while (check(-1)) {
		for (int i = 1; i <= n; i++)
			if (R[i] >= 0)
				L[i]--;
		mx++;
	}

	while (check(mx)) {
		for (int i = 1; i <= n; i++)
			if (R[i] >= 0)
				R[i]++;
		mx++;
	}

	string s, t;
	for (int i = 1; i <= n; i++) {
		if (R[i] >= 0) {
			for (int j = L[i]; j <= R[i]; j++)
				s.push_back(S[i][j]), t.push_back(T[i][j]);
			break;	
		}
	}

	for (int i = 1; i <= n; i++) {
		string c = rep(S[i], s, t);
		if (c != T[i]) return cout << "NO" << endl, 0;
	}

	cout << "YES" << endl << s << endl << t << endl;
	return 0;
}