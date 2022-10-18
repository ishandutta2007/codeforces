#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
int n,m;
#define f first
#define s second
typedef pair<int, int> S;
#define MAXN 200010
S tv[MAXN], prg[MAXN];
LL cst[MAXN];
map<int, int> dst;
int nct;
S eve[MAXN*4];
int ne;
LL ans;
int ap1, ap2;

map<int, int> mxs;

int clip(int x, int l, int r) {
	return x<l?l:x>r?r:x;
}
void update(LL v, int a1, int a2) {
	if (v > ans) {
		ans = v;
		ap1 = a1;
		ap2 = a2;
	}
}
S bst[MAXN*4];
void s_insert(int p, S v) {
	for (int r = p+1; r > 0; r -= r&-r) {
		if (bst[r] < v) bst[r] = v;
	}
}
S s_query(int p) {
	S ret(0,0);
	for(int r=p+1; r <= nct; r += r&-r) {
		if (ret < bst[r]) ret = bst[r];
	}
	return ret;
}

void lemon() {  
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &prg[i].f, &prg[i].s);
		dst[prg[i].f*2] = 0;
		dst[prg[i].s*2] = 0;
	}
	for (int i=0; i<m; i++) {
		int tc;
		scanf("%d%d%d", &tv[i].f, &tv[i].s, &tc);
		cst[i]=tc;
		dst[tv[i].f*2-1] = 0;
		dst[tv[i].s*2+1] = 0;
	}
	rept(it, dst) {
		it->second = nct++;
	}
	ne = 0;
	rep(i,0,n-1) {
		eve[ne++] = S(dst[prg[i].f*2], i);
	}
	rep(i,0,m-1) {
		eve[ne++] = S(dst[tv[i].f*2-1], i+n);
	}
	sort(eve, eve+ne);
	mxs.clear();
	rep(i,0,ne-1) {
		if (eve[i].s < n) {
			int ii = eve[i].s;
			mxs[-prg[ii].s] = ii;
		} else {
			int ii = eve[i].s - n;
			if (mxs.size()) {
				update((clip(-mxs.begin()->first, tv[ii].f, tv[ii].s) - tv[ii].f) * cst[ii], ii, mxs.begin()->second);
			}
		}
	}

	ne = 0;
	rep(i,0,n-1) {
		eve[ne++] = S(-dst[prg[i].s*2], i);
	}
	rep(i,0,m-1) {
		eve[ne++] = S(-dst[tv[i].s*2+1], i+n);
	}
	sort(eve, eve+ne);
	mxs.clear();
	rep(i,0,ne-1) {
		if (eve[i].s < n) {
			int ii = eve[i].s;
			mxs[prg[ii].f] = ii;
		} else {
			int ii = eve[i].s - n;
			if (mxs.size()) {
				update((tv[ii].s - (clip(mxs.begin()->first, tv[ii].f, tv[ii].s))) * cst[ii], ii, mxs.begin()->second);
			}
		}
	}

	repd(i,ne-1,0) {
		if (eve[i].s < n) {
			int ii = eve[i].s;
			s_insert(dst[prg[ii].f*2], S(prg[ii].s-prg[ii].f, ii));
		} else {
			int ii = eve[i].s - n;
			S ret = s_query(dst[tv[ii].f*2-1]);
			update(ret.f * cst[ii], ii, ret.s);
		}
	}
	cout << ans << endl;
	if (ans > 0) {
		printf("%d %d\n", ap2+1, ap1+1);
	}
}

int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}