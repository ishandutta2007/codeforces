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
T Abs(const T x){
	return x<0?-x:x;
}

#define MaxBuffer 20000000
class ReadBuffer{
	private:
	char buff[MaxBuffer];
	char *buf;
	public:
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
		buf=buff;
	}
	template<class T>
	bool readInteger(T &x)
	{
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag;
		flag=0;
		if(*buf=='-') flag=true;
		else x=*buf-'0';
		while(isdigit(*++buf)) x=x*10+*buf-'0';
		if(flag) x=-x;
		return true;
	}
	template<class T>
	bool readFloat(T &x)
	{
		long double nowpos=0.1;
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag,decimal;
		decimal=flag=0;
		if(*buf=='-') flag=true,++buf;
		else if(*buf=='.') decimal=true;
		while(isdigit(*buf)||*buf=='.')
		{
			if(*buf=='.') decimal=true;
			else
			{
				if(decimal)
				{
					x+=nowpos*(*buf-'0');
					nowpos*=0.1;
				}
				else
				{
					x=x*10+*buf-'0';
				}
			}
			++buf;
		}
		return true;
	}
	bool readChar(char c)
	{
		if(*buf==0) return 0;
		return c=*buf++,1;
	}
	bool readString(char *s)
	{
		while(*buf&&isspace(*buf)) ++buf;
		if(!*buf) return false;
		while(!isspace(*buf)) *s++=*buf++;
		*s++=0;
		return true;
	}
	int countSpacetonext(){
		int total=0;
		while(*buf&&*buf==' ') ++total,++buf;
		return total;
	}
	bool splitBycharactor(char *s,char Split='\n'){
		while(*buf&&*buf!=Split) *s++=*buf++;
		*s++=0;
		return *buf!=0;
	}
};

struct EDGE{
	int T;EDGE *Nxt;
};

pair<int,int> P[100100];
VI xx,yy;
int N;

PII preY[100100];
PII sufY[100100];

LL ans;

inline LL Sqr(const LL &x){
	return x*x;
}

inline LL Abs(const LL &x){
	return x<0?-x:x;
}

int main(){
	scanf("%d",&N);
	REP_1(i,N){
		scanf("%d%d",&P[i].X,&P[i].Y);
		xx.push_back(P[i].X);
		yy.push_back(P[i].Y);
	}
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	ans=min(Sqr(xx[0]-xx.back()),Sqr(yy[0]-yy.back()));
	sort(P+1,P+N+1);
	preY[0]=MP(1000000000,-1000000000);
	sufY[N+1]=MP(1000000000,-1000000000);
	REP_1(i,N){
		preY[i]=MP(min(preY[i-1].X,P[i].Y),max(preY[i-1].Y,P[i].Y));
	}
	DOW_1(i,N){
		sufY[i]=MP(min(sufY[i+1].X,P[i].Y),max(sufY[i+1].Y,P[i].Y));
	}
	LL left=-1,right=ans;
	while(left+1!=right){
		LL mid=(left+right)>>1;
		LL f=(LL)(sqrt((long double)mid)+1e-6);
		while(f*f<=mid) ++f;
		while(f*f>mid) --f;
		bool flag=false;
		REP_1(i,N){
			int aim;
			if(P[i].X<=0){
				if(Abs(P[i].X)*2<=f){
					aim=-P[i].X;
				}
				else{
					aim=P[i].X+f;
				}
				int g=lower_bound(P+i+1,P+N+1,MP(aim,1000000000))-P-1;
				int mminy=min(sufY[g+1].X,preY[i-1].X);
				int mmaxy=max(sufY[g+1].Y,preY[i-1].Y);
				if(mmaxy-mminy<=f&&Sqr(P[i].X)+Sqr(max(Abs(mminy),Abs(mmaxy)))<=mid){
					flag=true;
					break;
				}
			}
			else{
				if(Abs(P[i].X)*2<=f){
					aim=-P[i].X;
				}
				else{
					aim=P[i].X-f;
				}
				int g=lower_bound(P+1,P+i,MP(aim,-1000000000))-P;
				int mminy=min(preY[g-1].X,sufY[i+1].X);
				int mmaxy=max(preY[g-1].Y,sufY[i+1].Y);
				if(mmaxy-mminy<=f&&Sqr(P[i].X)+Sqr(max(Abs(mminy),Abs(mmaxy)))<=mid){
					flag=true;
					break;
				}
			}
		}
		if(flag) right=mid;
		else left=mid;
	}
	cout<<right<<endl;
	return 0;
}