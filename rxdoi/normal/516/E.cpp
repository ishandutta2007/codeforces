#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

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
typedef vector<int> Vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

map<int,int> vis;
map<int,Vi> Ma,Mb;
int n,m,g,x,c;
ll res;
Vi V;

void exgcd(int a,int b,ll &x,ll &y){
	if (!b){
		x=1;y=0;return;
	}
	exgcd(b,a%b,x,y);
	ll tmp=x;x=y;y=tmp-a/b*y;
}
int inv(int a,int p){
	ll x,y;
	exgcd(a,p,x,y);
	return (x+p)%p;
}
ll cal(Vi &V,map<int,int> &A,int m,int n){
	if (V.size()==n) return 0;
	map<int,int> C;
	int tmp=inv(m%n,n);
	for (map<int,int>::iterator i=A.begin();i!=A.end();i++){
		C[1ll*i->fi*tmp%n]=i->se;
	}
	map<int,int> Mv;
	For(i,0,V.size()){
		Mv[1ll*V[i]*tmp%n]=1;
	}
	vector<pii> T,S;
	for (map<int,int>::iterator i=C.begin();i!=C.end();i++) T.pb(*i);
	int p=0;
	For(i,1,T.size()) if (T[i].se<T[p].se) p=i;
	S.pb(T[p]);
	For(i,p+1,T.size()){
		if (S.back().se+1ll*(T[i].fi-S.back().fi+n)%n*m>T[i].se) S.pb(T[i]);
	}
	For(i,0,p){
		if (S.back().se+1ll*(T[i].fi-S.back().fi+n)%n*m>T[i].se) S.pb(T[i]);
	}
	Vi W;
	For(i,0,S.size()) W.pb(S[i].fi);
	sort(W.begin(),W.end());
	ll res=0;
	For(i,0,T.size()){
		int rank=(T[i].fi+n-1)%n;
		if (Mv.count(rank)) continue;
		int u=upper_bound(W.begin(),W.end(),rank)-W.begin();
		if (u==0) u=int(W.size())-1;else u--;
		res=max(res,C[W[u]]+1ll*(rank-W[u]+n)%n*m);
	}
	return res;
}
ll gao(Vi &Va,Vi &Vb){
	map<int,int> A,B;
	if (Va.size()==n&&Vb.size()==m) return -(1<<30);
	For(i,0,Va.size()){
		int x=Va[i];
		if (!A.count(x)||A[x]>x) A[x]=x;
		if (!B.count(x%m)||B[x%m]>x) B[x%m]=x;
	}
	For(i,0,Vb.size()){
		int x=Vb[i];
		if (!B.count(x)||B[x]>x) B[x]=x;
		if (!A.count(x%n)||A[x%n]>x) A[x%n]=x;
	}
	return max(cal(Va,A,m,n),cal(Vb,B,n,m));
}

int main(){
	n=IN(),m=IN();
	g=__gcd(n,m);
	n/=g,m/=g;
	for (int a=IN();a--;){
		x=IN();
		if (!vis[x%g]) vis[x%g]=1,V.pb(x%g),c++;
		Ma[x%g].pb(x/g);
	}
	for (int b=IN();b--;){
		x=IN();
		if (!vis[x%g]) vis[x%g]=1,V.pb(x%g),c++;
		Mb[x%g].pb(x/g);
	}
	if (c!=g){
		puts("-1");
		return 0;
	}
	For(i,0,V.size()){
		res=max(res,1ll*gao(Ma[V[i]],Mb[V[i]])*g+V[i]);
	}
	printf("%I64d\n",res);
}