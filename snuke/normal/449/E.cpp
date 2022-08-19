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
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1000005, INF = 1000010000;
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

vi p[MX];
mint x[MX], z[MX];
mint a1[MX], a2[MX], a3[MX];
int cnt[MX];
mint half;

void init() {
	half = mint(1)/2;
	rrep(i,MX-1) z[i] = z[i-1] + (mint(i) * i);
	for (int i = 2; i < MX; ++i) {
		for (int j = i; j < MX; j += i) {
			p[j].pb(i);
		}
	}
	for (int i = 1; i < MX; ++i) {
		rep(j,sz(p[i])) cnt[p[i][j]] = i / p[i][j];
		mint cr;
		drep(j,sz(p[i])) {
			int np = p[i][j];
			rep(k,sz(p[np])-1) cnt[p[np][k]] -= cnt[np];
			cr += cnt[np] * (np - 1);
		}
		mint wa = mint(i + 2)*(i+1)*(i) * half - z[i];
		mint now = (wa - 2*i - cr) * half;
		mint pro = mint(i) * i * i - now*4;
		a1[i] = a1[i-1] + pro;
		a2[i] = a2[i-1] + pro * mint(i-1)*(i-1);
		a3[i] = a3[i-1] + pro * (i-1);
	}
}

int main(){
	init();
	int ts;
	scanf("%d",&ts);
	rep(ti,ts){
		int n, m;
		scanf("%d%d",&n,&m);
		if (n > m) swap(n,m);
		mint ans = 0;
		ans += a1[n] * n * m;
		ans += a2[n];
		ans -= a3[n] * (n + m);
		printf("%I64d\n", ans.x);
	}
	
	return 0;
}