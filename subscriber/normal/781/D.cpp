#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

long long out[2][65][505][10];
long long in[2][65][505][10];

int ve[555], ve2[555];
int n, m;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		out[z][0][x][y / 64] |= pw(y % 64);
		in[z][0][y][x / 64] |= pw(x % 64);
	}

	for (int k = 1; k <= 64; k++) {
		for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
			int ok = 0;
			for (int i = 0; i < 10; i++) if (out[0][k - 1][x][i] & in[1][k - 1][y][i]) {
				ok = 1;
			}
			if (ok) {
				out[0][k][x][y / 64] |= pw(y % 64);
				in[0][k][y][x / 64] |= pw(x % 64);
			}
		}
		for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
			int ok = 0;
			for (int i = 0; i < 10; i++) if (out[1][k - 1][x][i] & in[0][k - 1][y][i]) {
				ok = 1;
			}
			if (ok) {
				out[1][k][x][y / 64] |= pw(y % 64);
				in[1][k][y][x / 64] |= pw(x % 64);
				
			}
		}
	}
	long long ans = 0;
	ve[0] = 1;
	int re = 0;

	for (int it = 61; it >= 0; it--) {
		int can = 0;
		for (int i = 0; i < n; i++) ve2[i] = 0;
		for (int x = 0; x < n; x++) if (ve[x]) for (int y = 0; y < n; y++) if (out[re][it][x][y / 64] & pw(y % 64)) {
			can = 1;
			ve2[y] = 1;
		}
		if (!can) continue;
		ans += pw(it);
		if (ans > 1000000000ll * 1000000000ll) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < n; i++) ve[i] = ve2[i];
		re ^= 1;
	}
	cout << ans << endl;


	return 0;
}