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

vector<pair<int, int> > v[N];
int n;

int get_list(int x, int y) {
	if (v[x].size() == 1) return x;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i].F != y) return get_list(v[x][i].F, x);
}

int ccount = 0;

void psolve(int x, int y, int we) {
	if (v[x].size() == 1) swap(x, y);
	if (v[x].size() == 1) {
		ccount += 1;
		return;
	}
	if (v[y].size() == 1) {
		ccount += 3;
		return;
	} 
	ccount += 4;

}



void solve(int x, int y, int we) {
	if (v[x].size() == 1) swap(x, y);
	if (v[x].size() == 1) {
		cout << x + 1 << " " << y + 1 << " " << we << endl;
		return;
	}
	int x1 = -1, x2 = -1;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i].F != y) {
		if (x1 == -1) x1 = get_list(v[x][i].F, x); else x2 = get_list(v[x][i].F, x);
	}
	if (v[y].size() == 1) {
		cout << x1 + 1 << " " << y + 1 << " " << we / 2 << endl;
		cout << x2 + 1 << " " << y + 1 << " " << we / 2 << endl;
		cout << x1 + 1 << " " << x2 + 1 << " " << -we / 2 << endl;
		return;
	} 
	int y1 = -1, y2 = -1;
	for (int i = 0; i < v[y].size(); i++) if (v[y][i].F != x) {
		if (y1 == -1) y1 = get_list(v[y][i].F, y); else y2 = get_list(v[y][i].F, y);
	}
	cout << x1 + 1 << " " << y1 + 1 << " " << we / 2 << endl;
	cout << x2 + 1 << " " << y2 + 1 << " " << we / 2 << endl;
	cout << x1 + 1 << " " << x2 + 1 << " " << -we / 2 << endl;
	cout << y1 + 1 << " " << y2 + 1 << " " << -we / 2 << endl;

}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		v[x].pb(mp(y, z));
		v[y].pb(mp(x, z));
	}
	for (int i = 0; i < n; i++) if (v[i].size() == 2) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) for (int j = 0; j < v[i].size(); j++) if (i < v[i][j].F) psolve(i, v[i][j].F, v[i][j].S);
	cout << ccount << endl;
	for (int i = 0; i < n; i++) for (int j = 0; j < v[i].size(); j++) if (i < v[i][j].F) solve(i, v[i][j].F, v[i][j].S);
	ios::sync_with_stdio(false);
	return 0;
}