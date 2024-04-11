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
#define N 311111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

const int M1 = 1000000007;
const int M2 = 1000000009;

int n;
int cc[N];
string ch;

set<pair<int, int> > S[N];
int u[N];

int mul1[N], mul2[N], add1[N], add2[N];

vector<int> v[N];

int pv(int x, int y, int mod) {
	long long r = 1;
	while (y > 0) {
		if (y & 1) r = r * x % mod;
		x = x * 1ll * x % mod;
		y >>= 1;
	}
	return r;
}

void dfs(int x, int p) {
	int li = 1;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) li = 0;
	if (li) {
		u[x] = x;
		int h1 = (ch[x] - 'a' + 1);
		int h2 = (ch[x] - 'a' + 1);
		S[x].insert(mp(h1, h2));
		mul1[x] = 1;
		add1[x] = 0;
		mul2[x] = 1;
		add2[x] = 0;
		cc[x] += 1;			
		return;
	}
	int ms = -1;
	int mx = -1;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p) continue;
		dfs(to, x);

		if (ms == -1 || S[u[to]].size() > ms) {
			ms = S[u[to]].size();
			mx = i;
		}
	}
	u[x] = u[v[x][mx]];

	add1[u[x]] = (add1[u[x]] * 31ll + (ch[x] - 'a' + 1)) % M1;
	add2[u[x]] = (add2[u[x]] * 37ll + (ch[x] - 'a' + 1)) % M2;

	mul1[u[x]] = mul1[u[x]] * 31ll % M1;
	mul2[u[x]] = mul2[u[x]] * 37ll % M2;

	int r1 =  pv(mul1[u[x]], M1 - 2, M1);
	int r2 =  pv(mul2[u[x]], M2 - 2, M2);

	set<pair<int, int> >::iterator it;
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i];
		if (to == p || i == mx) continue;

		for (it = S[u[to]].begin(); it != S[u[to]].end(); ++it) {
			int h1 = (*it).F;
			int h2 = (*it).S;

			h1 = (h1 * 1ll * mul1[u[to]] + add1[u[to]]) % M1;
			h2 = (h2 * 1ll * mul2[u[to]] + add2[u[to]]) % M2;

			h1 = (h1 * 31ll + (ch[x] - 'a' + 1)) % M1;
			h2 = (h2 * 37ll + (ch[x] - 'a' + 1)) % M2;

			h1 = (h1 - add1[u[x]] + M1);
			if (h1 < 0) h1 += M1;
			h1 = h1 * 1ll * r1 % M1;

			h2 = (h2 - add2[u[x]] + M2);
			if (h2 < 0) h2 += M2;
			h2 = h2 * 1ll * r2 % M2;

			S[u[x]].insert(mp(h1, h2));
		}
	}
	{	
			int h1 = (ch[x] - 'a' + 1);
			int h2 = (ch[x] - 'a' + 1);

//			h1 = (h1 * 1ll * mul1[u[x]] + add1[u[x]]) % M1;
//			h2 = (h2 * 1ll * mul2[u[x]] + add2[u[x]]) % M1;

			h1 = (h1 - add1[u[x]] + M1);
			if (h1 < 0) h1 += M1;
			h1 = h1 * 1ll * r1 % M1;

			h2 = (h2 - add2[u[x]] + M2);
			if (h2 < 0) h2 += M2;
			h2 = h2 * 1ll * r2 % M2;

			S[u[x]].insert(mp(h1, h2));
	}
	cc[x] += S[u[x]].size();			

}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cc[i];
	cin >> ch;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0, 0);
	int ans1 = -1, ans2 = 0;
	for (int i = 0; i < n; i++) if (cc[i] > ans1) {
		ans1 = cc[i];
		ans2 = 1;
	} else if (cc[i] == ans1) {
		ans2 ++;
	}
//	for (int i = 0; i < n; i++) cout << cc[i] << endl;
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}