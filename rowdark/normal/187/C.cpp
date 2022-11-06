/*
ID: rowdark1
LANG: C++
PROG:
*/

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

#define X first
#define Y second
#define REP_0(i,n)for(int i=0;i<(n);++i)
#define REP_1(i,n)for(int i=1;i<=(n);++i)
#define REP_2(i,a,b)for(int i=(a);i<(b);++i)
#define REP_3(i,a,b)for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c)for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n)for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n)for(int i=(n);0<i;--i)
#define DOW_2(i,a,b)for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b)for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b)for(a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b)for(a=(b).rbegin();a!=b.rend();++a)
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
T By(T x,T y,T P){
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
T Mul(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=By(F1,x,P);
		}
		x=By(x,x,P);
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

struct EDGE{
	int T;EDGE *Nxt;
	void init(const int _S,const int _T);
}E[400001],*V[100001],*PE;

void EDGE::init(const int _S,const int _T){
	T=_T,Nxt=V[_S],V[_S]=this;
}

template<class T>
void UpdataMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdataMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

bool In[100001];
bool Vol[100001];

int Dist[1000001];

int L,R,Mid;
int N,M,K,I,J,S,T;

int SPFA[100001],HH,TT;

bool Connect(){
	HH=-1,TT=0,In[S]=1;
	SPFA[0]=S;
	while(HH++!=TT)
	{
		I=SPFA[HH];
		if(I==T) return true;
		PE=V[I];
		while(PE)
		{
			if(!In[PE->T])
			{
				In[PE->T]=1;
				SPFA[++TT]=PE->T;
			}
			PE=PE->Nxt;
		}
	}
	return false;
}

bool Spfa(){
	memset(In,0,sizeof(In));
	memset(Dist,63,sizeof(Dist));
	Dist[S]=0;
	SPFA[0]=S;
	HH=-1,TT=0;
	In[S]=1;
	while(HH++!=TT)
	{
		if(HH==100001) HH=0;
		I=SPFA[HH];
		int L=HH+1;
		if(L==100001) L=0;
		if(I==T) return true;
		In[I]=0;
		if(Vol[I]) Dist[I]=0;
		if(Dist[I]==Mid) continue;
		PE=V[I];
		J=Dist[I]+1;
		while(PE)
		{
			if(J<Dist[PE->T])
			{
				Dist[PE->T]=J;
				if(!In[PE->T])
				{
					In[PE->T]=1;
					if(++TT==100001) TT=0;
					if(TT==L||Dist[SPFA[L]]<J)
					{
						SPFA[TT]=PE->T;
					}
					else
					{
						SPFA[TT]=SPFA[L],SPFA[L]=PE->T;
					}
				}
			}
			PE=PE->Nxt;
		}
	}
	return false;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	PE=E;
	scanf("%d%d%d",&N,&M,&K);
	L=0,R=N+1;
	REP_0(i,K) scanf("%d",&I),Vol[I]=1;
	REP_0(i,M) scanf("%d%d",&I,&J),PE++->init(I,J),PE++->init(J,I);
	scanf("%d%d",&S,&T);
	if(!Connect()) {printf("-1\n");goto end;}
	while(Mid=(L+R)>>1,L+1!=R)
	{
		if(Spfa()) R=Mid;
		else L=Mid;
	}
	printf("%d\n",R);
	end:;
	scanf("%d",&N);
	return 0;
}