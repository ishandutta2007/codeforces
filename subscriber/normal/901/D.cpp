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
vector<pair<int, int> > v[N];
int n, m;
int x[N], y[N], d[N];
int no[N];
long long ans[N];
long long c[N];

long long cur[N];


int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void go(int x, int pr, int dd) {

	d[x] = dd;
	for (pair<int, int> to : v[x]) if (to.F != pr) {
		go(to.F, x, dd + 1);	
	}
} 

void sol(int x, int pr) {
	for (pair<int, int> to : v[x]) if (to.F != pr) {
		sol(to.F, x);

		ans[to.S] = c[to.F] - cur[to.F];

		cur[to.F] += ans[to.S];
		cur[x] += ans[to.S];
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--;
		y[i]--;
	}
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		if (get(x[i]) == get(y[i])) {
			no[i] = 1;
			continue;
		}
		v[x[i]].pb(mp(y[i], i));
		v[y[i]].pb(mp(x[i], i));
		p[get(x[i])] = get(y[i]);
	}
	go(0, 0, 1);
	int cen = 0;
	int ed = -1;
	for (int i = 0; i < m; i++) if (no[i]) {
		if (d[x[i]] % 2 != d[y[i]] % 2) {
			ans[i] = 0;
			continue;
		}
		cen = x[i];
		ed = i;
		break;
	}
	sol(cen, cen);

	if (c[cen] != cur[cen] && ed == -1) {
		cout << "NO" << endl;
		return 0;
	}
	if (c[cen] == cur[cen]) {
		cout << "YES" << endl;
		for (int i = 0; i < m; i++) cout << ans[i] << endl;
		return 0;
	}
	long long need = c[cen] - cur[cen];
	for (int i = 0; i < n; i++) cur[i] = 0;

	ans[ed] = need / 2;
	cur[x[ed]] += ans[ed];
	cur[y[ed]] += ans[ed];
	sol(cen, cen);


	cout << "YES" << endl;
	for (int i = 0; i < m; i++) cout << ans[i] << endl;



	return 0;
}