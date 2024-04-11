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
#define N 2000222

#define TASK "1"

using namespace std;

vector<pair<int, int> > e;

int a[N], u[N], s[N], s2[N];

pair<int, pair<int, int> > fu[N];
int n;

pair<int, pair<int, int> > merg(pair<int, pair<int, int > > a, pair<int, pair<int, int > > b) {
	if (a.S.F == -1) return b;
	if (b.S.F == -1) return a;

	int co = a.F + b.F;
	pair<int, pair<int, int> > ret;

	if (e[a.S.F].F + a.S.S + b.F < e[b.S.F].F + b.S.S) {
		ret = mp(co, mp(a.S.F, a.S.S + b.F));
	} else {
		ret = mp(co, mp(b.S.F, b.S.S));
	}
	return ret;
}

void init(int pos, int l, int r) {
	if (l == r) {
		fu[pos] = mp(0, mp(-1, -1));
		return;
	}
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);
	fu[pos] = merg(fu[pos + pos], fu[pos + pos + 1]);
}

void upd(int pos, int l, int r, int x) {
	if (x < l || x > r) return;
	if (l == r) {
		fu[pos] = mp(1, mp(x, 0));
		return;
	}
	upd(pos + pos, l, (l + r) / 2, x);
	upd(pos + pos + 1, (l + r) / 2 + 1, r, x);
	fu[pos] = merg(fu[pos + pos], fu[pos + pos + 1]);
}

pair<int, pair<int, int> > get(int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return mp(0, mp(-1, -1));
	if (l == ll && r == rr) return fu[pos];

	return merg(get(pos + pos, l, (l + r) / 2, ll, rr), get(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr));
}

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

void add2(int x, int v) {
	while (x < n) {
		s2[x] = max(s2[x], v);
		x |= x + 1;
	}
}

int get2(int x) {
	int r = -1e9;
	while (x >= 0) {
		r = max(r, s2[x]);
		x = (x & (x + 1)) - 1;
	}
	return r;
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
		e.pb(mp(a[i], i));
	}
	sort(e.begin(), e.end());

	for (int i = 0; i < n; i++) u[e[i].S] = i;

	init(1, 0, n - 1);

	for (int i = 0; i < n; i++) s2[i] = -1e9;

	for (int i = 0; i < n; i++) {
		add(u[i], 1);
		add2(u[i], a[i]);
		int l = -1;
		int r = n - 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (get(mid) <= -get2(mid)) l = mid; else r = mid - 1;
		}	
		int st = l + 1;
		int x = -get(l);

		upd(1, 0, n - 1, u[i]);

		pair<int, pair<int, int> > gg = get(1, 0, n - 1, st, n - 1);

		int eva = x;
		if (gg.S.F != -1) eva = min(x + gg.F, e[gg.S.F].F + gg.S.S);
		cout << eva << endl;
	}

	return 0;
}