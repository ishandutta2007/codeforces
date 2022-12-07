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

int n;
vector<int> v[N];
int dist[N], pr[N], color[N];
vector<int> order;

int sz(int x, int p) {
	int ret = 1;
	for (int y : v[x]) if (y != p) ret += sz(y, x);
	return ret;
}

void rec(int x, int p, int o) {
	color[x] = o;
	order.pb(x);
	pr[x] = p;
	for (int y : v[x]) if (y != p) rec(y, x, o);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >>	x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	int c = -1;
	for (int i = 0; i < n; i++) {
		int ok = 1;
		for (int y : v[i]) if (sz(y, i) > n / 2) ok = 0;
		if (ok) {
			c = i;
			break;
		}
	}
	int s1 = 0, s2 = 0;

	int ma = -1;
	int id = -1;

	for (int y : v[c]) {
		int s = sz(y, c);
		if (s > ma) {
			ma = s;
			id = y;
		}
	}
	if (id != -1) s1 += sz(id, c);


	for (int y : v[c]) {
		int s = sz(y, c);
		if (y == id || s1 <= s2) {
			if (y != id) s1 += s;
			rec(y, c, 1);
		} else {
			s2 += s;
			rec(y, c, 2);
		}
		
	}
	int cur1 = 1;
	int cur2 = s1 + 1;
	for (int x : order) {
		if (color[x] == 1) {
			dist[x] = cur1; 
			cur1 += 1;
		} else {
			dist[x] = cur2;
			cur2 += s1 + 1;
		}
		cout << x + 1 << " " << pr[x] + 1 << " " << dist[x] - dist[pr[x]] << endl;
	}
	return 0;
}