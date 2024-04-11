// \_()_/
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

const ll MAXN = 5e5 + 10;
const ll AL = 26;

int n, m, B[MAXN], F[MAXN];
string s, t;
char C[MAXN][AL];
bool H[AL];

inline void Smth(char c1, char c2) {
	int k = 0;
	for (int i = 1; i < n + m + 1; i++) {
		while (k && B[i] != B[k])
			k = F[k - 1];
		F[i] = (k += (B[i] == B[k]));
		if (k == m && !C[i - m - 1][c1 - 'a']) C[i - m - 1][c1 - 'a'] = c2;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;

	for (char c1 = 'a'; c1 <= 'z'; c1++) {
		for (char c2 = 'a'; c2 <= 'z'; c2++) {
			string tmp = t + "#" + s;
			for (int i = 0; i < n + m + 1; i++) 
				B[i] = (tmp[i] == c1 && i < m) || (tmp[i] == c2 && i > m);	
			B[m] = 2;
			Smth(c1, c2);
		}
	}

	for (char c : t) H[c - 'a'] = true;

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(i - m + 2);
		for (int c = 'a'; c <= 'z'; c++) {
			char c2 = C[i][c - 'a'];
			if (H[c - 'a'] && (!c2 || (H[c2 - 'a'] && C[i][c2 - 'a'] != c))) {
				ans.pop_back();
				break;
			}
		}
	}
	
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}