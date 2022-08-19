#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

const int MX = 100505, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Mod int
const int mod = 1000000007;
struct mint;
mint ex(mint a, ll tms);
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x(x){}
	mint operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
	mint operator/=(const mint& a){ (x*=ex(a,mod-2).x)%=mod; return *this;}
	mint operator+(const mint& a)const{ return mint(*this) += a;}
	mint operator-(const mint& a)const{ return mint(*this) -= a;}
	mint operator*(const mint& a)const{ return mint(*this) *= a;}
	mint operator/(const mint& a)const{ return mint(*this) /= a;}
};
mint ex(mint a, ll tms){
	if(!tms) return 1;
	mint res = ex(a,tms/2);
	res *= res;
	return (tms&1)?res*a:res;
}
//
typedef pair<mint,mint> P;

char c[MX];

mint d[MX], l[MX];
vector<int> t[MX];

vector<int> et[10], ep[10];

P dfs(int v) {
	if (v < 0) return P(v+10,10);
	if (d[v].x != -1) {
		return P(d[v],l[v]);
	}
	d[v].x = 0; l[v].x = 1;
	mint a = 1;
	drep(i,sz(t[v])) {
		P res = dfs(t[v][i]);
		mint nd = res.fi;
		mint nl = res.se;
		//cout << nd.x << " " << nl.x << endl;
		d[v] += a*nd;
		l[v] *= nl;
		a *= nl;
	}
	return P(d[v],l[v]);	
}

int main(){
	int q;
	scanf("%s",c);
	string s = c;
	t[0].resize(sz(s),-1);
	rep(i,sz(s)){
		et[s[i]-'0'].pb(0);
		ep[s[i]-'0'].pb(i);
		t[0][i] = s[i]-'0'-10;
	}

	scanf("%d",&q);
	rrep(qi,q){
		scanf("%s",c);
		string u = c;
		int x = c[0]-'0';
		u = u.substr(3);
		t[qi].resize(sz(u),-1);
		rep(i,sz(et[x])){
			int ti = et[x][i];
			int p = ep[x][i];
			t[ti][p] = qi;
		}
		et[x].clear(); ep[x].clear();
		rep(i,sz(u)){
			et[u[i]-'0'].pb(qi);
			ep[u[i]-'0'].pb(i);
			t[qi][i] = u[i]-'0'-10;
		}
	}

	rep(i,q+1) d[i] = -1;
	
	cout << dfs(0).fi.x << endl;
	
	return 0;
}