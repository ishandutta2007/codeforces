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
};

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

LL Sum[100011];

int F[100011];

LL Biao[100011];

int N,G,R,M,I,J,K,L,T,Q;

LL Ans;

LL ANSF[100011];

int LT[262170];

int Get(int L,int R){
	--L,++R;
	L+=131072,R+=131072;
	int Ans=0x3f3f3f3f;
	while(L^R^1)
	{
		if(~L&1) UpdataMin(Ans,LT[L^1]);
		if(R&1) UpdataMin(Ans,LT[R^1]);
		L>>=1,R>>=1;
	}
	return Ans;
}

void Put(int Pos,int Val){
	Pos+=131072;
	while(Pos)
	{
		LT[Pos]=Val;
		Pos>>=1;
	}
}

int FL,FR;
int FFL,FFR,RNow;
int PP;

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d%d",&N,&G,&R);
	scanf("%d",&PP);
	REP_3(i,2,N+1) scanf("%d",&I),Sum[i]=Sum[i-1]+I,Biao[i+2]=Sum[i]%(G+R);
	Biao[1]=-1,Biao[N+3]=G+R;
	sort(Biao+1,Biao+N+4);
	M=unique(Biao+1,Biao+N+4)-Biao;
	REP_1(i,N) F[i]=LB(Biao+1,Biao+M+1,(int)(Sum[i]%(G+R)))-Biao;
	memset(LT,63,sizeof(LT));
	DOW_1(i,N)
	{
		FL=(Sum[i]+G)%(G+R);
		FR=(Sum[i])%(G+R);
		FFL=LB(Biao+1,Biao+M+1,FL)-Biao;
		FFR=LB(Biao+1,Biao+M+1,FR)-Biao;
		if(FL<FR)
		{
			if(FFL==FFR)
			{
				ANSF[i]=Sum[N+1]-Sum[i];
			}
			else
			{
				RNow=Get(FFL,FFR-1);
				if(RNow!=0x3f3f3f3f)
				{
					ANSF[i]=ANSF[RNow]+((Sum[RNow]-Sum[i])/(G+R)+((Sum[RNow]-Sum[i])%(G+R)!=0))*(G+R);
				}
				else
				{
					ANSF[i]=Sum[N+1]-Sum[i];
				}
			}
		}
		else
		{
			RNow=min(Get(1,FFR-1),Get(FFL,M));
			if(RNow!=0x3f3f3f3f)
			{
				ANSF[i]=ANSF[RNow]+((Sum[RNow]-Sum[i])/(G+R)+((Sum[RNow]-Sum[i])%(G+R)!=0))*(G+R);
			}
			else
			{
				ANSF[i]=Sum[N+1]-Sum[i];
			}
		}
		Put(F[i],i);
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&T);
		T+=PP;
		I=T%(G+R);
		FL=G-I;
		if(FL<0) FL+=G+R;
		FR=-I+G+R;
		if(FR==G+R) FR=0;
		FFL=LB(Biao+1,Biao+M+1,FL)-Biao;
		FFR=LB(Biao+1,Biao+M+1,FR)-Biao;
		if(FL<FR)
		{
			if(FFL==FFR)
			{
				Ans=Sum[N+1]+T;
			}
			else
			{
				RNow=Get(FFL,FFR-1);
				if(RNow!=0x3f3f3f3f)
				{
					Ans=ANSF[RNow]+((Sum[RNow]+T)/(G+R)+((Sum[RNow]+T)%(G+R)!=0))*(G+R);
				}
				else
				{
					Ans=Sum[N+1]+T;
				}
			}
		}
		else
		{
			RNow=min(Get(1,FFR-1),Get(FFL,M));
			if(RNow!=0x3f3f3f3f)
			{
				Ans=ANSF[RNow]+((Sum[RNow]+T)/(G+R)+((Sum[RNow]+T)%(G+R)!=0))*(G+R);
			}
			else
			{
				Ans=Sum[N+1]+T;
			}
		}
		printf("%I64d\n",Ans);
	}
	scanf("%d",&N);
	return 0;
}