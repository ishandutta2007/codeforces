#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
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
typedef pair<int,int> pt;

int ans = 0;

int n, m;
vector<int> v[N][2];

vector<pair<int, int> > e[N];

int was[N];

vector<int> cur[2];

void ae(int x, int y, int r) {
	e[x].pb(mp(y, r));
	e[y].pb(mp(x, r));

//	cout << x << " " << y << " " << r << endl;
}

int bad = 0;

void go(int x) {
	for (int i = 0; i < e[x].size(); i++) {
		int to = e[x][i].F;

		int r = e[x][i].S;

		if (was[to] != -1) {
			if (was[to] != was[x] ^ r) bad = 1;
			continue;
		}
		was[to] = was[x] ^ r;
		cur[was[to]].pb(to);
		go(to);
	}
}


vector<int> solve(int ch) {
	for (int i = 0; i < n; i++) e[i].clear();

	for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < v[i][j].size(); k++) {
		int to = v[i][j][k];

		//ae(i, to, j ^ ch);

		e[i].pb(mp(to, j ^ ch));
		//e[to].pb(mp(i, j ^ ch));
	}
	vector<int> ans;

	for (int i = 0; i < n; i++) was[i] = -1;
	bad = 0;
	for (int i = 0; i < n; i++) if (was[i] == -1) {
		cur[0].clear();
		cur[1].clear();
		
		cur[0].pb(i);
		was[i] = 0;

		go(i);
		if (cur[0].size() > cur[1].size()) swap(cur[0], cur[1]);

		for (int j = 0; j < cur[0].size(); j++) ans.pb(cur[0][j]);
	}
	//cout << ch << " " << bad << " " << ans.size() << endl;
	if (bad) {
		ans.clear();
		ans.pb(-1);
	}
	return ans;
	
}


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		char t;

		cin >>x >> y >> t;
		if (x == y) continue;

		int b = (t == 'R');

		x--;
		y--;

		v[x][b].pb(y);
		v[y][b].pb(x);
	}

	vector<int> t1 = solve(0);
	vector<int> t2 = solve(1);

	vector<int> ans = t1;
	if ((t1.size() == 1 && t1[0] == -1) || ((t2.size() != 1 || t2[0] != -1) && t2.size() < t1.size())) ans = t2;

	if (ans.size() == 1 && ans[0] == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1;
		if (i + 1 == ans.size()) cout << endl; else cout << " ";
	}


	return 0;
}