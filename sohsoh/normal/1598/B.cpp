//: // ////: ///  / : //// / :
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

const ll MAXN = 1e5 + 10;

bool C[5][MAXN];

inline int solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			cin >> C[j][i];

	if (n & 1) return cout << "NO" << endl, 0;

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int a = 0, b = 0, c = 0;
			for (int k = 1; k <= n; k++) {
				if (C[i][k] && C[j][k]) c++;
				else if (C[i][k]) a++;
				else if (!C[j][k]) b++;
			}

			if (b == 0 && n / 2 >= a && n / 2 <= a + c) return cout << "YES" << endl, 0;
		}
	}

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