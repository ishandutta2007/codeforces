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

int n;
int e[2022][2022];
int e2[2022][2022];
long long d[2022];
int w[2022];
int f[2022];
int ok[2022];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	int mi = 1e9 + 10;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> e[i][j];
			e[j][i] = e[i][j];

			mi = min(mi, e[i][j]);
		}
	}
	for (int i = 0; i <n; i++) for (int j = 0; j < n; j++) if (i != j) e[i][j] -= mi;


	for (int i = 0; i < n; i++) {
		w[i] = 1e9 + 1;
		for (int j = 0;  j< n; j++) if (i != j) w[i] = min(w[i], e[i][j]);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) e2[i][j] = e[i][j];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) e2[i][j] = min(e2[i][j], w[i] * 2);

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j && e[i][j] == 0) ok[i] = 1;

	for (int i = 0; i < n; i++) d[i] = 1e18 + 10;
	for (int i = 0; i < n; i++) if (ok[i]) d[i] = 0;

	for(;;) {
		int x = -1;
		for (int i = 0; i < n; i++) if (!f[i] && (x == -1 || d[i] < d[x])) x = i;
		if (x == -1) break;
		f[x] = 1;

		for (int i = 0; i < n; i++) {
			int dd = d[x] + e2[i][x];
			if (dd < d[i]) d[i] = dd;
		}
	}
	for (int i = 0; i < n; i++) cout << d[i] + mi * 1ll * (n - 1) << endl;
	return 0;
}