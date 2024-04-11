#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;

int main() {
	df(n);
	vp p;
	rep(i,n) {
		df(s); df(d);
		int t = s+d-1;
		bool ok = true;
		rep(j,sz(p)) {
			if (p[j].fi <= t && p[j].se >= s) ok = false;
		}
		if (!ok) {
			int pre = 1;
			rep(j,sz(p)) {
				if (pre+d-1 < p[j].fi) break;
				pre = p[j].se+1;
			}
			s = pre; t = s+d-1;
		}
		p.pb(P(s,t));
		printf("%d %d\n", s, t);
		sort(rng(p));
	}
	return 0;
}