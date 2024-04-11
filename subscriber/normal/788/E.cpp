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

vector<int> e;


vector<int> ids[N];

int a[N], li[N], s[N];
int A[N], B[N];
int n;    


void add(int x, int v) {
	while (x < n) {
		s[x] += v;
		x |= x + 1;
	}
}

int get(int x) {
	int r = 0;
	while (x >= 0) {
		r += s[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
}

vector<int> E, Q[N], cur[N];


vector<vector<int> > su[N];

void init(int tt, int pos, int l, int r) {
	if (l == r) {
		su[tt][pos] = cur[ids[tt][l]];
		return;
	}
	init(tt, pos + pos, l, (l + r) / 2);
	init(tt, pos + pos + 1, (l + r) / 2 + 1, r);

	su[tt][pos] = vector<int>(16, 0);

	for (int i = 0; i < 4; i++) for (int j = i; j < 4; j++) for (int k = i; k<= j; k++) {
		su[tt][pos][(i << 2) + j] = (su[tt][pos][(i << 2) + j] + su[tt][pos + pos][(i << 2) + k] * 1ll * su[tt][pos + pos + 1][k * 4 + j]) % M;
	}
}

void mod(int tt, int pos, int l, int r, int x) {
	if (x < l || x > r) return;
	if (l == r) {
		su[tt][pos] = cur[ids[tt][l]];
		return;
	}
	mod(tt, pos + pos, l, (l + r) / 2, x);
	mod(tt, pos + pos + 1, (l + r) / 2 + 1, r, x);

	for (int i = 0; i< 16; i++) su[tt][pos][i] = 0;

	for (int i = 0; i < 4; i++) for (int j = i; j < 4; j++) for (int k = i; k<= j; k++) {
		su[tt][pos][(i << 2) + j] = (su[tt][pos][(i << 2) + j] + su[tt][pos + pos][(i << 2) + k] * 1ll * su[tt][pos + pos + 1][k * 4 + j]) % M;
	}
}



int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		e.pb(a[i]);
	}
	sort(e.begin(), e.end());
	e.resize(unique(e.begin(), e.end()) - e.begin());
	for (int i = 0; i < n; i++) a[i] = lower_bound(e.begin(), e.end(), a[i]) - e.begin();

	for (int i = 0; i < n; i++) {
		ids[a[i]].pb(i);
		li[i] = ids[a[i]].size() - 1;
	}

	for (int i = 0; i < e.size(); i++) {
		for (int j = 0; j < ids[i].size(); j++) {
			int x = ids[i][j];

			A[x] = get(x - 1) + j;
			B[x] = get(n - 1) - get(x) + (ids[i].size() - 1 - j);
		}
		for (int j = 0; j < ids[i].size(); j++) {
			int x = ids[i][j];
			add(x, 1);
		}	
	}
	for (int i = 0; i < 16; i++) E.pb(0);
	for (int i = 0; i < 4; i++) E[i * 4 + i] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j< 16; j++) Q[i].pb(0);
		for (int j = 0; j < 4; j++) Q[i][j * 4 + j] = 1;

		Q[i][0 * 4 + 1] = A[i];
		Q[i][1 * 4 + 2] = 1;
		Q[i][2 * 4 + 3] = B[i];
	}
	for (int i = 0; i < n; i++) cur[i] = Q[i];

	int ans = 0;

	for (int i = 0; i < e.size(); i++) {
		su[i].resize(ids[i].size() * 4);
		init(i, 1, 0, ids[i].size() - 1);

		ans = (ans + su[i][1][0 * 4 + 3]) % M;
		
	}
	int q;
	cin >> q;
	while (q--) {
		int ty, x;
		cin >> ty >> x;
		x--;
		if (ty == 1) {
			cur[x] = E;
		} else {
			cur[x] = Q[x];
		}
		ans = (ans - su[a[x]][1][0 * 4 + 3] + M) % M;
		mod(a[x], 1, 0, ids[a[x]].size() - 1, li[x]);
		ans = (ans + su[a[x]][1][0 * 4 + 3]) % M;

		cout << ans  << endl;
	}



	return 0;
}