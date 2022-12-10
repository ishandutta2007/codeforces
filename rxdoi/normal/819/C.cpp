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
typedef long double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

map<int,int> N,M,S,T;
vector<pii> V;
ll n,m,s,res;

void gao(ll &x,map<int,int> &M,int n){
	x*=n;
	for (int d=2;d*d<=n;d++){
		while (n%d==0) n/=d,M[d]++;
	}
	if (n>1) M[n]++;
}
void Dfs(int i,ll x){
	if (x>n) return;
	if (i==V.size()){
		res++;
		return;
	}
	For(j,0,V[i].se){
		Dfs(i+1,x);
		if (db(1.0)*x*V[i].fi>5e18) return;
		x*=V[i].fi;
	}
	Dfs(i+1,x);
}
void Dfs(int i,ll x,int f){
	if (x==0) return;
	if (i==V.size()){
		res+=f*x;
		return;
	}
	Dfs(i+1,x,f);
	For(j,0,V[i].se+1) x/=V[i].fi;
	Dfs(i+1,x,-f);
}
void Main(){
	N.clear();n=1;
	M.clear();m=1;
	S.clear();s=1;
	For(i,0,3) gao(n,N,IN());
	For(i,0,3) gao(m,M,IN());
	For(i,0,3) gao(s,S,IN());
	gao(s,S,2);
	res=0;
	V.clear();
	for (pii A:S) V.pb(A);
	Dfs(0,1);
	T.clear();
	for (pii A:N){
		if (!S.count(A.fi)||A.se>S[A.fi]) T[A.fi]=S[A.fi];
	}
	V.clear();
	for (pii A:T) V.pb(A);
	Dfs(0,m,1);
	printf("%I64d\n",res);
}

int main(){
	for (int T=IN();T--;) Main();
}