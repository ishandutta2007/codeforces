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

int n, m, ps[MAXN];
bool R[2][MAXN], F[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int ind = i & 1;
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			R[ind][j] = (c == 'X');
			if (R[ind][j] && R[1 - ind][j + 1]) F[j] = true;
		}
	}

	for (int i = 1; i <= m; i++)
		ps[i] = ps[i - 1] + F[i];

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (ps[r - 1] - ps[l - 1]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}