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

const int C = 100111;

vector<int> d[2][666000];
int n, m, k;
int x[N], y[N];
long long ans[N];

long long inf = (long long) 1e18 + 1;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];


		d[0][x[i] + y[i] + C].pb(i);
		d[1][x[i] - y[i] + C].pb(i);
		ans[i] = inf;
	}
	int a = 0;
	int b = 0;
	int da = 1;
	int db = 1;
	long long T = 0;
	for(;;) {
		int l = 0;
		int r = 1e6 + 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			int aa = a + mid * da;
			int bb = b + mid * db;
			if (0 <= aa && aa <= n && 0 <= bb && bb <= m) l = mid; else r = mid - 1;
		}
		int ty = 0;
		if (da * db == 1) ty = 1;

		int h = a + b + C;
		if (ty == 1) h = a - b + C;

		for (int i = 0; i < d[ty][h].size(); i++) {
			int id = d[ty][h][i];

			int add = abs(x[id] - a);
			ans[id] = min(ans[id], T + add);
		}
		T += l;
		a += da * l;
		b += db * l;

		if ((a == 0 || a == n) && (b == 0 || b == m)) break;
		if (a == 0 || a == n) da *= -1;
		if (b == 0 || b == m) db *= -1;
	}	
	for (int i = 0; i < k; i++) {
		if (ans[i] >= inf) ans[i] = -1;
		cout << ans[i] << endl;
	}
	return 0;
}