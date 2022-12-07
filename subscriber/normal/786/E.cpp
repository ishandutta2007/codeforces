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

int G;
int S, T;

vector<pair<int, int> > v[N];
vector<int> rev[N];

int u[N], d[N];

int par[18][N];
int dep[N];

int cnt[N];

int id[N], gs[N];

int n, m;

int Qx[N], Qy[N], Ex[N], Ey[N];

int q[N], q1, q2;

vector<int> vv[N];
int st;

int mag = 100;


void go(int x, int pr, int d) {
	dep[x] = d;
	cnt[d % mag]++;
	for (int i = 0; i < vv[x].size(); i++) {
		int to = vv[x][i];
		if (to == pr) continue;
		par[0][to] = x;
		go(to, x, d + 1);
	}
}

int lca(int x, int y) {
	for (int i = 16; i >= 0; i--) if (dep[par[i][x]] >= dep[y]) x = par[i][x];
	for (int i = 16; i >= 0; i--) if (dep[par[i][y]] >= dep[x]) y = par[i][y];

	if (x == y) return x;
	for (int i = 16; i >= 0; i--) if (par[i][x] != par[i][y]) {
		x = par[i][x];
		y = par[i][y];
	}
	return par[0][x];
}

void ae(int x, int y, int fl) {
	v[x].pb(mp(y, fl));
	v[y].pb(mp(x, 0));

	rev[x].pb(v[y].size() - 1);
	rev[y].pb(v[x].size() - 1);
}

int go(int x, int o) {
	if (o == 0 || x == T) return o;
	int ret = 0;

	while (u[x] < v[x].size()) {
		int to = v[x][u[x]].F;
		if (d[x] + 1 != d[to]) {
			u[x]++;
			continue;
		}
		int l = go(to, min(o, v[x][u[x]].S));

		if (l == 0) {
			u[x]++;
			continue;
		}

		ret += l;
		o -= l;
		v[x][u[x]].S -= l;
		v[to][rev[x][u[x]]].S += l;
	}
	return ret;
}


int need[N];

void cs(int x, int pr) {
	for (int i = 0; i < vv[x].size(); i++) {
		int to = vv[x][i];
		if (to == pr) continue;
		cs(to, x);
		need[x] += need[to];
	}
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;

	map<pair<int, int>, int> ddd;
	for (int i = 1; i < n; i++) {
		cin >> Ex[i] >> Ey[i];
		Ex[i]--;
		Ey[i]--;

		vv[Ex[i]].pb(Ey[i]);
		vv[Ey[i]].pb(Ex[i]);


		ddd[mp(Ex[i], Ey[i])] = i;
		ddd[mp(Ey[i], Ex[i])] = i;
	}
	par[0][0] = 0;
	go(0, 0, 0);
	for (int i = 1; i < 17; i++) for (int j = 0; j < n; j++) par[i][j] = par[i - 1][par[i - 1][j]];

	G = 0;
	for (int i = 1; i < mag; i++) if (cnt[i] < cnt[G]) G = i;

	S = m + n;
	T = S + 1;

	st = T;

	for (int i = 0; i < n; i++) if (dep[i] % mag == G && dep[i] >= mag) {
		st++;
		int x = i;
		for (int j = 0; j < mag; j++) {
			ae(st, m + x, 1e6);
			x = par[0][x];
		}
		id[i] = st;
		gs[i] = x;
	}
	for (int i = 0; i < m; i++) {
		cin >> Qx[i] >> Qy[i];
		Qx[i]--;
		Qy[i]--;

		int z = lca(Qx[i], Qy[i]);
		int x = Qx[i];

		while (x != z) {
			while (dep[x] % mag == G && dep[x] - dep[z] >= mag) {
				ae(i, id[x], 1);
				x = gs[x];					
			}
			if (x == z) break;	
			ae(i, m + x, 1);
			x = par[0][x];
		}
		x = Qy[i];
		while (x != z) {
			while (dep[x] % mag == G && dep[x] - dep[z] >= mag) {
				ae(i, id[x], 1);
				x = gs[x];					
			}	
			if (x == z) break;	
			ae(i, m + x, 1);
			x = par[0][x];
		}
	}
	for (int i = 0; i < m; i++) ae(S, i, 1);
	for (int i = 0; i < n; i++) ae(m + i, T, 1);

	int aa = 0;
	for(;;) {
		for (int i = 0; i <= st; i++) d[i] = -1;
		d[S] = 0;
		q1 = q2 = 0;
		q[q1++] = S;
		while (q1 != q2) {
			int x = q[q2++];
			for (int i = 0; i < v[x].size(); i++) {
				int to = v[x][i].F;
				if (v[x][i].S == 0) continue;
				if (d[to] != -1) continue;
				d[to] = d[x] + 1;
				q[q1++] = to;
			}
		}
		if (d[T] == -1) break;
		for (int i = 0; i <= st; i++) u[i] = 0;
		aa += go(S, 1e9);
	}
	cout << aa << endl;
//	cout << n - 1 + m - aa << endl;
        {
		for (int i = 0; i <= st; i++) d[i] = -1;
		d[S] = 0;
		q1 = q2 = 0;
		q[q1++] = S;
		while (q1 != q2) {
			int x = q[q2++];
			for (int i = 0; i < v[x].size(); i++) {
				int to = v[x][i].F;
				if (v[x][i].S == 0) continue;
				if (d[to] != -1) continue;
				d[to] = d[x] + 1;
				q[q1++] = to;
			}
		}
        }
        vector<int> A;
        for (int i = 0; i < m; i++) if (d[i] == -1) {
        	A.pb(i + 1);
	} else {
		need[Qx[i]]++;
		need[Qy[i]]++;


		int z = lca(Qx[i], Qy[i]);

		need[z] -= 2;
	}

	cs(0, 0);

        cout << A.size();
        for (int i = 0; i < A.size(); i++) cout << " " << A[i];
        cout << endl;

        vector<int> B;
        for (int i = 0; i < n; i++) if (need[i] > 0) B.pb(ddd[mp(i, par[0][i])]);

        cout << B.size();
        for (int i = 0; i < B.size(); i++) cout << " " << B[i];
        cout << endl;



	return 0;
}