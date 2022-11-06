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

int n,m;
int c[1001][1001];
long long sumx,sumy;
long long total;
int fx,fy;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&m);
	REP_0(i,n) REP_0(j,m) scanf("%d",c[i]+j),sumx+=c[i][j]*(i*4+2),sumy+=c[i][j]*(j*4+2),total+=c[i][j];
	if(total==0){puts("0\n0 0");return 0;}
	total*=4;
	fx=sumx/total,sumx%=total;
	fy=sumy/total,sumy%=total;
	fx+=sumx*2>total;
	fy+=sumy*2>total;
	total=0;
	REP_0(i,n) REP_0(j,m) total+=(Sqr((LL)i*4+2-fx*4)+Sqr((LL)j*4+2-fy*4))*c[i][j];
	cout<<total<<endl<<fx<<' '<<fy<<endl;
	return 0;
}