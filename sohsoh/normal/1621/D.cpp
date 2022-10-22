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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;

int n;
ll C[MAXN][MAXN], rps[MAXN][MAXN], rss[MAXN][MAXN], cps[MAXN][MAXN], css[MAXN][MAXN];
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 10; i++)
			for (int j = 0; j < n + 10; j++)
				rps[i][j] = cps[i][j] = rss[i][j] = css[i][j] = C[i][j] = 0;
		cin >> n;
		n *= 2;
		ll s = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> C[i][j];
				if (i > n / 2 && j > n / 2) {
					s += C[i][j];
					C[i][j] = 0;
				}

				rps[i][j] = rps[i][j - 1] + C[i][j];
				cps[i][j] = cps[i - 1][j] + C[i][j];
			}
		}

		for (int i = n; i > 0; i--) {
			for (int j = n; j > 0; j--) {
				rss[i][j] = rss[i][j + 1] + C[i][j];
				css[i][j] = css[i + 1][j] + C[i][j];
			}
		}

		cout << min({C[1][n / 2 + 1], C[1][n], C[n / 2][n / 2 + 1], C[n / 2][n],
				C[n / 2 + 1][1], C[n / 2 + 1][n / 2], C[n][1], C[n][n / 2]}) + s << endl;		
	}
	return 0;
}