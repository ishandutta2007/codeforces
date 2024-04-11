#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T Mul(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Pow(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=Mul(F1,x,P);
		}
		x=Mul(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdateMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

int in[1000001];
queue<int> Q[100001];
int n;

const int mod=1000000007;

LL a[200001];
LL inva[200001];
LL inv[1000001];

LL c[200001];

inline void ins(int x,LL v){
	if(v>=mod) v%=mod;
	while(x<=n){
		c[x]*=v;
		if(c[x]>=mod) c[x]%=mod;
		x+=x&-x;
	}
}

inline LL pro(int x){
	LL ret=1;
	while(x){
		ret*=c[x];
		if(ret>=mod) ret%=mod;
		x^=x&-x;
	}
	return ret;
}

int idp[1000001];
int prime[1000001];
LL ans[200001];
vector<pair<int,int> > QQ[200001];
vector<int> inQ[200001];
int pid;

int main(){
	for(int i=1;i<=1000000;++i){
		inv[i]=i==1?1:mod-mod/i*inv[mod%i]%mod;
	}
	for(int i=2;i<=1000000;++i) if(!in[i]){
		idp[i]=++pid;
		prime[pid]=i;
		for(int j=i;j<=1000000;j+=i){
			in[j]=i;
		}
	}
	scanf("%d",&n);
	a[0]=1;
	inva[0]=1;
	REP_1(i,n){
		int x;
		scanf("%d",&x);
		a[i]=a[i-1]*x%mod;
		inva[i]=inva[i-1]*inv[x]%mod;
		while(in[x]){
			int v=in[x];
			x/=v;
			if(v!=in[x]){
				Q[idp[v]].push(i);
				inQ[i].push_back(idp[v]);
			}
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		QQ[x].push_back(make_pair(y,i));
	}
	REP_1(i,n) c[i]=1;
	for(int i=1;i<=pid;++i){
		if(!Q[i].empty()){
			ins(Q[i].front(),inv[prime[i]]*(prime[i]-1));
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<int(QQ[i].size());++j){
			ans[QQ[i][j].second]=a[QQ[i][j].first]*inva[i-1]%mod*pro(QQ[i][j].first)%mod;
		}
		for(int j=0;j<int(inQ[i].size());++j){
			int x=inQ[i][j];
			ins(i,inv[prime[x]-1]*prime[x]);
			if(i!=Q[x].front()) while(1);
			Q[x].pop();
			if(!Q[x].empty()){
				ins(Q[x].front(),inv[prime[x]]*(prime[x]-1));
			}
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",int(ans[i]));
	scanf("%d",&n);
	return 0;
}