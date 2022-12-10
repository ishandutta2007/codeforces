#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef pair<ll,ll> pll;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;

int ans[N];
int T,n,inv;
ll s[N],m,w;
map<int,vector<pii> > V;

void exgcd(int a,int b,ll &x,ll &y){
	if (!b){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
}
int cal(int a,int b){
	ll x,y;
	exgcd(a,b,x,y);
	return (x+b)%b;
}
void gao(int r,vector<pii> V){
	map<int,int> M;
	For(i,0,V.size()){
		V[i].se=(V[i].se-r)/w;
		if (!M.count(V[i].se)){
			M[V[i].se]=V[i].fi;
		}
	}
	vector<pii> A;
	for (pii p:M){
		A.pb(mp(1ll*p.fi*inv%T,p.se));
	}
	sort(A.begin(),A.end());
	For(i,0,A.size()-1){
		ans[A[i].se]+=A[i+1].fi-A[i].fi;
	}
	ans[A.back().se]+=T-A.back().fi+A[0].fi;
}

int main(){
	T=IN();n=IN();
	For(i,1,n+1) s[i]=s[i-1]+IN();
	m=s[n];
	w=__gcd(m,0ll+T);
	inv=cal((m/w)%(T/w),T/w);
	For(i,1,n+1){
		V[s[i]%w].pb(mp(i,s[i]%T));
	}
	m/=w,T/=w;
	for (auto i:V){
		gao(i.fi,i.se);
	}
	For(i,1,n+1) printf("%d ",ans[i]);
	puts("");
}