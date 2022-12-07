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
#define N 211111

#define TASK "1"

using namespace std;

int M[2] = {1000000007, 1000000009};

int pv(int a, int b, int m) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2, m);
	r = r * r % m;
	if (b % 2) r = r * a % m;
	return r;
}

vector<pair<int, int> > z[N];
int n, m;
int len[N];

int full[2], a[2], b[2], zam[2], su[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		z[x].pb(mp(i, 0));
		z[y].pb(mp(i, 1));
		len[i] = (y - x + 1) % 2;

		su[x] += 1;
		su[y + 1] -= 1;

	}
	for (int i = 1; i < n; i++) su[i] += su[i - 1];

	full[0] = full[1] = 0;

	a[0] = a[1] = 0;
	b[0] = b[1] = 0;

	zam[0] = zam[1] = 0;

	map<pair<int, int>, int> cnt;

	map<pair<int, int>, long long> sum;



	long long ans = 0;

	for (int i = 0; i < n; i++) {

		cnt[mp((a[0] + zam[0]) % M[0], (a[1] + zam[1]) % M[1])]++;


		sum[mp((a[0] + zam[0]) % M[0], (a[1] + zam[1]) % M[1])] += i;


//		cout << "+ " << (a[0] + zam[0]) % M[0] << " " << (a[1] + zam[1]) % M[1] << endl;

		swap(a[0], b[0]);
		swap(a[1], b[1]);

		for (int j = 0; j < z[i].size(); j++) if (z[i][j].S == 0) {
			int id = z[i][j].F;
			for (int u = 0; u < 2; u++) {
				int t = pv(2, id, M[u]);
				full[u] = (full[u] + t) % M[u];
				a[u] = (a[u] + t) % M[u];
			}
		}

		for (int j = 0; j < z[i].size(); j++) if (z[i][j].S == 1) {
			int id = z[i][j].F;
			for (int u = 0; u < 2; u++) {
				int t = pv(2, id, M[u]);

				if (len[id]) zam[u] = (zam[u] - t + M[u]) % M[u]; else zam[u] = (zam[u] + t) % M[u];

				if (len[id]) b[u] = (b[u] + t) % M[u]; else b[u] = (b[u] - t + M[u]) % M[u];
			}
		}
		ans += (i + 1) * 1ll * cnt[mp((full[0] - a[0] + M[0]) % M[0], (full[1] - a[1] + M[1]) % M[1])];
		ans -= sum[mp((full[0] - a[0] + M[0]) % M[0], (full[1] - a[1] + M[1]) % M[1])];



//		cout << "? " << (full[0] - a[0] + M[0]) % M[0] << " " << (full[1] - a[1] + M[1]) % M[1] << endl;
//		cout << "cur " << ans << endl;
	}

	long long empty = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (su[i] == 0) {
			s++;
		} else {
			empty += s * 1ll * (s + 1) * (s + 2) / 6;
			s = 0;
		}
	}
	empty += s * 1ll * (s + 1) * (s + 2) / 6;

	ans -= empty;
	cout << ans << endl;


	return 0;
}