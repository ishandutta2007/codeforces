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
#define N 411111
 
#define TASK "1"
 
using namespace std;

set<int> solve(vector<vector<int> > & a, int r) {
	int m = a[r].size();
	set<int> ret;
	for (int i = 1; i < m; i++) if (a[r][i] < a[r][i - 1]) {
		ret.insert(i - 1);
		ret.insert(i);
		int x = i;
		while (x + 1 < m && a[r][x + 1] == a[r][x]) x++;
		int y = i - 1;
		while (y - 1 >= 0 && a[r][y - 1] == a[r][y]) y--;
		ret.insert(x);
		ret.insert(y);
		if (ret.size() > 20) return ret;
	}
	return ret;
}
 
int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	int ts;
	cin >> ts;
	while (ts--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > a(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

		set<int> w;
		for (int i = 0; i < n; i++) {
			auto v = solve(a, i);
			w.merge(v);
			if (w.size() > 20) break;
		}
		if (w.size() == 0) w.insert(0);

		int ax = -1;
		int ay = -1;

		for (int x : w) for (int y : w) {
			for (int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
			bool check = true;
			for (int i = 0; i < n; i++) for (int j = 1; j < m; j++) if (a[i][j] < a[i][j - 1]) check = false;
			if (check) {
				ax = x;
				ay = y;
			}
			for (int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
		}
		if (ax == -1) cout << -1 << endl; else cout << ax + 1 << " " << ay + 1 << endl;
	}		
	return 0;
}