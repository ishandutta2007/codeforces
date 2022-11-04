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

inline long double Sqrt(const long double &x){
	return x<0?x:sqrt(x);
}

struct Tree{
	long double x;
	long double y;
	long double rot;
	void rotate(const LD &r){
		rot+=r;
		long double coR=cos(r),siR=sin(r);
		long double nx=coR*x-siR*y,ny=siR*x+coR*y;
		x=nx,y=ny;
	}
	void addLength(const LD &l){
		long double nl=l+Sqrt(x*x+y*y);
		x=cos(rot)*nl,y=sin(rot)*nl;
	}
}T[1048580];

inline void pushdown(int x,int lc,int rc){
	if(T[x].rot!=0){
		T[lc].rotate(T[x].rot);
		T[rc].rotate(T[x].rot);
		T[x].rot=0;
	}
}

void setLength(int x,int l,int r,int length,int now){
	if(l==r){
		T[now].addLength(length);
		return;
	}
	pushdown(now,now*2,now*2+1);
	int mid=(l+r)>>1;
	if(x<=mid) setLength(x,l,mid,length,now*2);
	else setLength(x,mid+1,r,length,now*2+1);
	T[now].x=T[now*2].x+T[now*2+1].x;
	T[now].y=T[now*2].y+T[now*2+1].y;
}

void setRot(int ll,int rr,int l,int r,const long double &x,int now){
	if(l==ll&&r==rr){
		T[now].rotate(x);
		return;
	}
	pushdown(now,now*2,now*2+1);
	int mid=(l+r)>>1;
	if(rr<=mid) setRot(ll,rr,l,mid,x,now*2);
	else if(ll>mid) setRot(ll,rr,mid+1,r,x,now*2+1);
	else setRot(ll,mid,l,mid,x,now*2),setRot(mid+1,rr,mid+1,r,x,now*2+1);
	T[now].x=T[now*2].x+T[now*2+1].x;
	T[now].y=T[now*2].y+T[now*2+1].y;
}

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	REP_1(i,n) setLength(i,1,n,1,1);
	REP_1(i,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			setLength(y,1,n,z,1);
		}
		else{
			setRot(y,n,1,n,-z*PI/180,1);
		}
		printf("%.10f %.10f\n",(double)T[1].x,(double)T[1].y);
	}
	return 0;
}