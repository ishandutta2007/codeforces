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

int p[N];
long long xo[N];

int x[N], y[N];
long long c[N];
long long ed[N];

vector<pair<int, int> > v[N];

int was[N];

int n, m;

int have[111];

vector<long long> a;

int get(int x) {
	if (p[x] == x) return x;

	get(p[x]);
	xo[x] = xo[x] ^ xo[p[x]];
	p[x] = p[p[x]];
	return p[x];
}

void getx(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i].F;
		int id = v[x][i].S;
		if (ed[id] < 0) {
			if (!was[to]) {
				was[to] = 1;
				getx(to);
			}
		} else {
			a.pb(ed[id]);
		}
	}
}

long long pop = 0;
int sz[N], cnt[N];

void go(int x, int pr, int b) {
	sz[x] = 0;
	cnt[x] = 0;

	for (int i = 0; i < v[x].size(); i++) {
		int to = v[x][i].F;
		if (to == pr) continue;
		if (ed[v[x][i].S] >= 0) continue;

		go(to, x, b);

		int s = sz[to];
		int ed = cnt[to];

		if (c[v[x][i].S] & pw(b)) ed = s - ed;

		pop += cnt[x] * 1ll * (s - ed);
		pop += (sz[x] - cnt[x]) * 1ll * ed;

		sz[x] += s;
		cnt[x] += ed;
	}
	pop += cnt[x];
	sz[x]++;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> c[i];
		x[i]--;
		y[i]--;
		v[x[i]].pb(mp(y[i], i));
		v[y[i]].pb(mp(x[i], i));
	}
	for (int i = 0; i < n; i++) p[i] = i, xo[i] = 0;

	for (int i = 0; i < m; i++) {
		if (get(x[i]) != get(y[i])) {
			int xx = get(x[i]);
			int yy = get(y[i]);
			
			long long g = c[i] ^ xo[x[i]] ^ xo[y[i]];

			p[xx] = yy;
			xo[xx] = g;

			ed[i] = -1;
		} else {
			long long X = c[i] ^ xo[x[i]] ^ xo[y[i]];

			ed[i] = X;
		}
	}
	int ans = 0;
	for (int ii = 0; ii < n; ii++) if (!was[ii]) {
		a.clear();
		was[ii] = 1;
		getx(ii);
		for (int i = 0; i < 61; i++) {
			have[i] = 0;
			for (int j = 0; j < a.size(); j++) if (a[j] & pw(i)) have[i] = 1;
		}	
		vector<long long> bs;
		for (int i = 60; i >= 0; i--) {
			int x = -1;
			for (int j = 0; j < a.size(); j++) if (a[j] & pw(i)) x = j;
			if (x == -1) continue;
			bs.pb(a[x]);
			for (int j = 0; j < a.size(); j++) if (a[j] & pw(i)) a[j] ^= bs.back();
		}
//		cout << "bs : " << bs.size() << endl;

		for (int i = 0; i < 61; i++) {
			pop = 0;
			go(ii, ii, i);

			long long all = sz[ii] * 1ll * (sz[ii] - 1) / 2;

			long long add = 0;
			if (have[i] == 0) {
				add = pop % M * 1ll * (pw(bs.size()) % M) % M;
			} else {
				add = (all % M * 1ll * (pw(bs.size() - 1) % M)) % M;
			}
			add = add * 1ll * (pw(i) % M) % M;
			ans = (ans + add) % M;
		}			
	}
	cout << ans << endl;
		
	return 0;
}