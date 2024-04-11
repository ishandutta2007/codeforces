/*
ID: rowdark1
LANG: C++
PROG:
*/

#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<sstream>
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
#define FOREACH(a,b) for(typeof(b.begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof(b.rbegin()) a=(b).rbegin();a!=b.rend();++a)
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

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

int n;
int a[60],p,sum=0;

long long pre[61];

long long dp[60][60];

long double ans=0;

LD deal(LL x,int y,int n){
	LD xx=(LD)x*y;
	int z=n-y-1;
	while(y)
	{
		xx=xx/(n--)*(y--);
	}
	while(z)
	{
		xx=xx/(n--)*(z--);
	}
	return xx;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	REP_1(i,n) cin>>a[i],sum+=a[i];
	cin>>p;
	if(sum<=p)
	{
		ans=n;
	}
	else
	{
		REP_1(i,n)
		{
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			REP_1(j,n)
			{
				if(i!=j)
				{
					int rem=j-(i<j);
					DOW_0(k,rem)
					{
						REP_0(l,p-a[j]+1)
						{
							dp[k+1][l+a[j]]+=dp[k][l];
						}
					}
				}
			}
			REP_0(j,n+1)
			{
				REP_3(k,p-a[i]+1,p)
				{
					pre[j]+=dp[j][k];
				}
			}
		}
		REP_1(i,n-1)
		{
			ans+=deal(pre[i],i,n);
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	cin>>n;
	return 0;
}