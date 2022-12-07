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
#define N 811111

#define TASK "1"

using namespace std;

int sp[N][26];

vector<pair<int, char> > v[N], z[N];

int h[N];
int saved[N];
int li[N];

int n;
int sz[N];

void dfs(int x, int pr) {
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i].F;
		if (to != pr) {
			z[x].pb(mp(to, v[x][i].S));
			sp[x][v[x][i].S - 'a'] = v[x][i].F;
			h[to] = h[x] + 1;
			dfs(to, x);
		}
	}	
}

int st;

int put(int fr, int to, int w) {
	li[to] += w;

	int ret = 0;

	for (int i = 0; i < z[fr].size(); i++) {
		int ch = z[fr][i].S - 'a';

		if (sp[to][ch]) {
			ret++;
			ret += put(z[fr][i].F, sp[to][ch], w);
			if (li[sp[to][ch]] == 0) sp[to][ch] = 0;
		} else {
			sp[to][ch] = st++;
			ret += put(z[fr][i].F, st - 1, w);
		}
	}	
	return ret;
}

void go(int x) {
	sz[x] = 1;
	for (int i = 0; i < z[x].size(); i++) {
		go(z[x][i].F);
		sz[x] += sz[z[x][i].F];
	}
	int la = 0;
	for (int i = 1; i < z[x].size(); i++) if (sz[z[x][i].F] > sz[z[x][la].F]) la = i;

	int val = z[x].size();

	st = n;

	for (int i = 0; i < z[x].size(); i++) if (i != la) {
		val += put(z[x][i].F, z[x][la].F, 1);
	}

	saved[h[x]] += val;

	for (int i = 0; i < z[x].size(); i++) if (i != la) {
		put(z[x][i].F, z[x][la].F, -1);
	}

}


int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		x--;
		y--;
		v[x].pb(mp(y, c));
		v[y].pb(mp(x, c));
	}
	h[0] = 0;
	dfs(0, 0);

	for (int i = 0; i < n; i++) li[i] = 1;

	go(0);
	int x = 0;
	for (int i = 1; i < n; i++) if (saved[i] > saved[x]) x = i;
	cout << n - saved[x] << endl;
	cout << x + 1 <<endl;
	return 0;
}