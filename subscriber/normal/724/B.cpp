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

int n, m;
int a[222][222];

void check() {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) if (a[i][j] != j + 1) cnt++;
		if (cnt > 2) return;
	}
	cout << "YES\n";
	exit(0);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

	check();

	for (int x = 0; x < m; x++) for (int y = 0; y < x; y++) {
		for (int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
		check();
		for (int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
	}
	cout << "NO\n";

	return 0;
}