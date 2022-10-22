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

const ll MAXN = 5e3 + 5;

ll p[2], t[2], f[MAXN][MAXN][2], h, s;

inline void mn(ll& a, ll b) {
	a = min(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(f, 63, sizeof f);
	f[0][0][0] = f[0][0][1] = 0;
	cin >> p[0] >> t[0] >> p[1] >> t[1] >> h >> s;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 2; k++) {
				ll tot = j * t[k];
				ll jp = tot / t[k ^ 1];
				ll rem = t[k], remp = t[k ^ 1] - tot % t[k ^ 1];

				ll tar = min(h, i + (p[0] + p[1] - s));
				mn(f[tar][0][0], f[i][j][k] + max(rem, remp));
				mn(f[tar][0][1], f[i][j][k] + max(rem, remp));
				
				if (rem < remp) {
					tar = min(h, i + (p[k] - s));
					mn(f[tar][j + 1][k], f[i][j][k] + rem);
				}

				if (remp < rem && jp + 1 < MAXN) {
					tar = min(h, i + (p[k ^ 1] - s));
					mn(f[tar][jp + 1][k ^ 1], f[i][j][k] + remp);
				}
			}
		}
	}

	ll ans = f[h][0][0];
	for (int i = 1; i < MAXN; i++)
		ans = min({ans, f[h][i][0], f[h][i][1]});
	cout << ans << endl;
	return 0;
}