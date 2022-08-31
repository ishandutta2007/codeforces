#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;

const int INF = 1001001001;

int dp[105][10105];

int f(int a, int b) {
	printf("? %d %d\n", a+1, b+1);
	fflush(stdout);
	char c;
	scanf(" %c",&c);
	if (c == '=') return 0;
	if (c == '<') return -1;
	return 1;
}

int main() {
	df(ts);
	rep(ti,ts) {
		df(n);
		vi a, b;
		rep(i,n/2) {
			int s = i*2, t = s+1;
			int r = f(s,t);
			if (r == 1) swap(s,t);
			a.pb(s); b.pb(t);
		}
		if (n&1) a.pb(n-1);
		if (n&1) b.pb(n-1);
		while (sz(a) > 1) {
			vi p; swap(p,a);
			rep(i,sz(p)/2) {
				int s = p[i*2], t = p[i*2+1];
				if (f(s,t) == 1) a.pb(t); else a.pb(s);
			}
			if (sz(p)&1) a.pb(p.back());
		}
		while (sz(b) > 1) {
			vi p; swap(p,b);
			rep(i,sz(p)/2) {
				int s = p[i*2], t = p[i*2+1];
				if (f(s,t) == -1) b.pb(t); else b.pb(s);
			}
			if (sz(p)&1) b.pb(p.back());
		}
		printf("! %d %d\n", a[0]+1, b[0]+1); fflush(stdout);
	}
	return 0;
}