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

const int MAXN = 1e5 + 10;
const int MAXM = 10 + 4;
const int SQ = 500;

char C[MAXN][MAXM];
int n, m, q;
pll ans[MAXN][MAXM];

inline void calc(int ind) {
	for (int i = ind * SQ + 1; i <= min(n, (ind + 1) * SQ); i++) {
		for (int j = 1; j <= m; j++) {
			ans[i][j] = {-1, -1};
			if (C[i][j] == '^') {
				if (i == ind * SQ + 1) ans[i][j] = {i - 1, j};
				else ans[i][j] = ans[i - 1][j];
			} else if (C[i][j] == '<') ans[i][j] = ans[i][j - 1];
		}

		for (int j = m; j > 0; j--)
			if (C[i][j] == '>') ans[i][j] = ans[i][j + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		ans[i][0] = {i, 0};
		ans[i][m + 1] = {i, m + 1};
		for (int j = 1; j <= m; j++) cin >> C[i][j];
	}

	for (int i = 0; i * SQ + 1 <= n; i++) calc(i);
	while (q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		
		if (c == 'A') {
			pll tans = {x, y};
			while (tans.X > 0 && tans.Y > 0 && tans.Y <= m)
				tans = ans[tans.X][tans.Y];

			cout << tans.X << sep << tans.Y << endl;
		} else {
			cin >> c;
			C[x][y] = c;
			if (x % SQ == 0) x--;
			calc(x / SQ);
		}
	}
	return 0;
}