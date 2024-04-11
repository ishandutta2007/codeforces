#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 100005, INF = 2000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

P w[MX];

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	rep(i,m) scanf("%d%d",&w[i].fi,&w[i].se);
	w[m++] = P(n+1,n-1);
	
	if(n == 1){
		if(m == 0) cout << 0 << endl;
		else cout << -1 << endl;
		return 0;
	}
	
	sort(w,w+m);
	
	int k = 0;
	vi l, r, nl, nr, pl, pr;
	l.pb(1); r.pb(1);
	int pw = 0;
	
	for(int i = 0; i < m;){
		int si = i;
		while(i < m && w[si].fi == w[i].fi) i++;
		if(w[si].fi-1 == pw){
			pl = l; pr = r;
		} else {
			pl.clear(); pr.clear();
			pl.pb(l[0]);
			pr.pb(n);
		}
		pw = w[si].fi;
		l.clear(); r.clear();
		
		int d = 1;
		for(int h = si; h < i; h++){
			if(d != w[h].se){
				nl.pb(d);
				nr.pb(w[h].se-1);
			}
			d = w[h].se+1;
		}
		if(d != n+1){
			nl.pb(d);
			nr.pb(n);
		}
		
		pl.pb(INF); pr.pb(INF);
		rep(j,nl.size()){
			int ri = lower_bound(rng(pr),nl[j])-pr.begin();
			if(pl[ri] <= nr[j]){
				l.pb(max(nl[j],pl[ri]));
				r.pb(nr[j]);
			}
		}
		/*
		rep(j,nl.size()) printf("%d ",nl[j]); puts("");
		rep(j,nr.size()) printf("%d ",nr[j]); puts("");
		rep(j,l.size()) printf("%d ",l[j]); puts("");
		rep(j,r.size()) printf("%d ",r[j]); puts("");
		rep(j,pl.size()) printf("%d ",pl[j]); puts("");
		rep(j,pr.size()) printf("%d ",pr[j]); puts("\n");//*/
		
		nl.clear(); nr.clear();
		if(l.size() == 0){ puts("-1"); return 0;}
	}
	
	if(r[(int)r.size()-1] == n) cout << n*2-2 << endl;
	else cout << -1 << endl;
	
	return 0;
}