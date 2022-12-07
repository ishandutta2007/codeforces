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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, q;
int mi[2][888000];

int xx[N], yy[N];
char ty[N];

void init(int tt, int pos, int l, int r) {
	mi[tt][pos] = 1e9 + 1;
	if (l == r) return;
	init(tt, pos + pos, l, (l + r) >> 1);
	init(tt, pos + pos + 1, ((l + r) >> 1) + 1, r);
}

int get(int tt, int pos, int l, int r, int ll, int rr) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return (int)1e9 + 1;

	if (l == ll && r == rr) return mi[tt][pos];

	return min(get(tt, pos + pos, l, (l + r) >> 1, ll, rr), 
	get(tt, pos + pos + 1, ((l + r) >> 1) + 1, r, ll, rr));
}

void upd(int tt, int pos, int l, int r, int x, int v) {
	if (x < l || x > r) return;
	if (l == r) {
		mi[tt][pos] = v;
		return;
	}
	upd(tt, pos + pos, l, (l + r) >> 1, x, v);
	upd(tt, pos + pos + 1, ((l + r) >> 1) + 1, r, x, v);

	mi[tt][pos] = min(mi[tt][pos + pos], mi[tt][pos + pos + 1]);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> q;

	vector<pair<int, int> > H, V;

	for (int i = 0; i < q; i++) {
		cin >> xx[i] >> yy[i] >> ty[i];

		if (ty[i] == 'L') H.pb(mp(xx[i], i)); else V.pb(mp(xx[i], i));
	}
	sort(H.begin(), H.end());
	sort(V.begin(), V.end());

	set<pair<int, int> > was;
	
	if (V.size() > 0 && H.size() > 0) {

		init(0, 1, 0, H.size() - 1);
		init(1, 1, 0, V.size() - 1);
	}

	for (int i = 0; i < q; i++) {	
		if (was.count(mp(xx[i], yy[i])) > 0) {
			cout << "0\n";
			continue;
		}
		was.insert(mp(xx[i], yy[i]));

		int mt;
		if (ty[i] == 'U') {
			mt = upper_bound(H.begin(), H.end(), mp(xx[i], i + 1000000)) - H.begin();;
		} else {
			mt = upper_bound(V.begin(), V.end(), mp(xx[i], i + 1000000)) - V.begin() - 1;
		}

		int last = -5;
		int lb;

		int l = 1;
		int r = n;
		while (l < r) {
			int mid = (l + r + 1) / 2;

			int endp;
			if (ty[i] == 'U') {
				endp = yy[i] - mid + 1;
			} else {
				endp = xx[i] - mid + 1;
			}

			if (endp < 1) {
				r = mid - 1;
				continue;
			}
			if (V.size() == 0 || H.size() == 0) {
				l = mid;
				continue;
			}
			int gr;
			if (ty[i] == 'U') gr = xx[i]; else gr = yy[i];

			int ii;

			int sz;
			int tt;
			int ll , rr;                                                       
			if (ty[i] == 'U') {                                              
				sz = H.size();
				tt = 0;
				ll = mt;
				rr = upper_bound(H.begin(), H.end(), mp(xx[i] + mid - 1, 1000000)) - H.begin() - 1;
				ii = rr;
			} else {
				sz = V.size();
				tt = 1;
				ll = lower_bound(V.begin(), V.end(), mp(xx[i] - mid + 1, 0)) - V.begin();
				rr = mt;
				ii = ll;
			}
			int bad = 0;

			if (ii == last) {
				bad = lb;
			} else {
				if (get(tt, 1, 0, sz - 1, ll, rr) <= gr) bad = 1;
				lb = bad;
				last = ii;
			}				
			if (bad) r = mid - 1; else l = mid;

		}
		cout << l << "\n";

		if (ty[i] == 'U') {
			int t = lower_bound(V.begin(), V.end(), mp(xx[i], i)) - V.begin();
			upd(1, 1, 0, V.size() - 1, t, yy[i] - l + 1);
		} else {
			int t = lower_bound(H.begin(), H.end(), mp(xx[i], i)) - H.begin();
			upd(0, 1, 0, H.size() - 1, t, xx[i] - l + 1);
		}

	}

	return 0;
}