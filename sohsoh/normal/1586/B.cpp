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

const ll MAXN = 1e6 + 10;

bool B[MAXN];
int n, m;

inline int solve() {
	for (int i = 0; i < n + 10; i++) B[i] = false;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		B[b] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (!B[i]) {
			for (int j = 1; j <= n; j++)
				if (j != i)
					cout << j << sep << i << endl;
			return 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}