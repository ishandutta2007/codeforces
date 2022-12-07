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

int h, w, n;

pair<int, int> mi[N];

set<pair<int, int> > se[N];

pair<pair<int, int>, pair<int, int> > q[N];

void upd(int pos, int l, int r, int x) {	
	if (x < l || x > r) return;
	if (l == r) {	
		if (se[l].size() == 0) {
			mi[pos] = mp((int)1e9 + 100, -1);
		} else {
			mi[pos] = mp(se[l].begin() -> F, l);
		}
		return;
	}
	upd(pos + pos, l, (l + r) / 2, x);
	upd(pos + pos + 1, (l + r) / 2 + 1, r, x);
	mi[pos] = min(mi[pos + pos], mi[pos + pos + 1]);
}

pair<int, int> get(int pos, int l, int r, int ll, int rr) {	
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return mp((int)1e9 + 100, -1);
	if (l == ll && r == rr) return mi[pos];

	return min( get(pos + pos, l, (l + r) / 2, ll, rr), 
	get(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr));
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		cin >> q[i].F.F >> q[i].S.F >> q[i].S.S >> q[i].F.S;
		q[i].S.F--;
		q[i].S.S--;
	}
	sort(q, q + n);

	for (int i = 0; i < w; i++) {
		se[i].insert(mp(h + 1, 1));
		upd(1, 0, w - 1, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		int l = q[i].S.F;
		int r = q[i].S.S;
		int here = 0;
		for(;;) {
			pair<int, int> t = get(1, 0, w - 1, l, r);
			if (t.S == -1) break;
			if (t.F > q[i].F.F + q[i].F.S) break;

			here = (here + se[t.S].begin() -> S) % M;
			se[t.S].erase(se[t.S].begin());
			upd(1, 0, w - 1, t.S);
		}
		if (l == 0 || r == w - 1) here = (here + here) % M;
		if (l != 0) {
			se[l - 1].insert(mp(q[i].F.F, here));
			upd(1, 0, w - 1, l - 1);
		}
		if (r != w - 1) {
			se[r + 1].insert(mp(q[i].F.F, here));
			upd(1, 0, w - 1, r + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < w; i++) for (auto it = se[i].begin(); it != se[i].end(); it++) ans = (ans + it -> S) % M;
	cout << ans << endl;
	return 0;
}