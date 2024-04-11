#include <cstdio>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define pb push_back
using namespace std;
typedef long long ll;

struct dat {
	int lim; ll d, mx;
	dat(){}
	dat(int lim, ll d, ll mx):lim(lim),d(d),mx(mx){}
	inline bool operator<(const dat& a) const { return lim < a.lim;}
};

vector<int> s;
struct seg {
	int sz;
	vector<int> tm;
	vector<vector<dat> > d;
	seg(){}
	seg(int mx) {
		sz = 1;
		while(sz <= mx) sz <<= 1;
		tm.resize(sz<<1);
		d.resize(sz<<1);
	}
	void init() {
		for (int i = (sz<<1)-1; i >= 1; --i) {
			if (i != 1) {
				int p = i>>1;
				d[p].insert(d[p].end(), d[i].begin(), d[i].end());
			}
			d[i].pb(dat(0,0,0));
			sort(d[i].begin(), d[i].end());
			rep(j, (int)d[i].size()-1) {
				d[i][j+1].d += d[i][j].d;
				d[i][j+1].mx += d[i][j].mx;
			}
		}
	}
	ll sum(int a, int b, int t, int i=1, int l=0, int r=-1) {
		if (r == -1) r = sz;
		ll res = 0;
		if (a <= l && r <= b && tm[i]) {
			t -= tm[i];
			int p = lower_bound(d[i].begin(), d[i].end(), dat(t,-1,-1))-d[i].begin()-1;
			res += (d[i].back().d - d[i][p].d) * t;
			res += d[i][p].mx;
			tm[i] += t;
			return res;
		}
		if (r-l == 1) {
			res = min(d[i].back().d * t + s[i-sz], d[i].back().mx);
			tm[i] = t;
			return res;
		}
		int c = l+r>>1;
		tm[i<<1] = max(tm[i<<1], tm[i]);
		tm[i<<1|1] = max(tm[i<<1|1], tm[i]);
		if (a < c) res += sum(a,b,t,i<<1,l,c);
		if (c < b) res += sum(a,b,t,i<<1|1,c,r);
		if (a <= l && r <= b) tm[i] = t; else tm[i] = 0;
		return res;
	} 
};

int main() {
	int n, q;
	scanf("%d",&n);
	seg d(n);
	s.resize(n);
	rep(i,n) {
		int m, g;
		scanf("%d%d%d",&s[i],&m,&g);
		d.d[d.sz+i].pb(dat(g?m/g:1<<30, g, m));
	}
	d.init();
	scanf("%d",&q);
	rep(qi,q) {
		int t, l, r;
		scanf("%d%d%d",&t,&l,&r); --l;
		printf("%I64d\n", d.sum(l,r,t));
	}
	return 0;
}