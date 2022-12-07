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
#define N 411111

#define TASK "1"

using namespace std;

int main(){
	#ifdef home
//		freopen(TASK".in","r",stdin);	
//		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i <n; i++) for (int j = 0; j < n; j++) a[i][j] = -1;
	a[0][0] = 1;
	a[0][1] = 1;
	a[n - 1][n - 1] = 0;
	for (int it = 0; it < 2 * n * n	; it++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][j] == -1) {
		int x = -1, y = -1;

		for (int dx = -2; dx <= 2; dx++) for (int dy = -2; dy <= 2; dy++) if (abs(dx) + abs(dy) == 2) {
			if (dx < 0 && dy > 0 || dx > 0 && dy < 0) continue;
			int xx = i + dx;
			int yy = j + dy;
			if (xx < 0 || xx >= n || yy < 0 || yy >= n || a[xx][yy] == -1) continue;
			x = xx;
			y = yy;
		}
		if (x == -1) continue;
		cout << "? " << min(x, i) + 1 << " " << min(y, j) + 1 << " " << max(x, i) + 1 << " " << max(j, y) + 1 << endl;
		int t;
		cin >> t;
		if (t == 1) a[i][j] = a[x][y]; else a[i][j] = a[x][y] ^ 1;
	}
	int nf = 0;
	int change = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int o = 0; o < pw(3); o++) if (!nf) {
		vector<int> e;
		int x = i;
		int y = j;
		e.pb(a[x][y]);
		for (int k = 0; k < 3; k++) {
			if (o & pw(k)) x++; else y++;
			if (x == n || y == n) break;
			e.pb(a[x][y]);
		}
		if (e.size() < 4) continue;
		if (e[0] != e[2] || e[1] != e[3]) continue;

		nf = 1;

		cout << "? " << min(x, i) + 1 << " " << min(y, j) + 1 << " " << max(x, i) + 1 << " " << max(j, y) + 1 << endl;
		int t;
		cin >> t;

		if (e[0] == e[1] && t == 0 || e[0] != e[1] && t == 1) change = 1;
	} 
	//if (!nf) for(;;);
	if (!nf) change = 1;
	if (change) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if ((i + j) % 2) a[i][j] ^= 1;



	cout << "!" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << a[i][j];
		cout << endl;
	}

	return 0;
}