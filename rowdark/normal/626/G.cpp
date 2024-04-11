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

set<pair<LD,int> > sadd,srem;

int a[200001];
int b[200001];
int v[200001];
int cnt;

long double totv;

inline long double getVal(int bet,int tot,int vp){
	return (LD)(tot-bet)/(tot-1)/(tot)*vp;
}

inline void changeA(int x,int delta){
	sadd.erase(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	srem.erase(MP(getVal(b[x],a[x]+b[x],v[x]),x));
	totv-=(LD)b[x]/(a[x]+b[x])*v[x];
	a[x]+=delta;
	if(a[x]<b[x]) --b[x],--cnt;
	totv+=(LD)b[x]/(a[x]+b[x])*v[x];
	if(b[x]!=a[x]) sadd.insert(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	if(b[x]) srem.insert(MP(getVal(b[x],a[x]+b[x],v[x]),x));
}

inline void removeId(int x){
	sadd.erase(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	srem.erase(MP(getVal(b[x],a[x]+b[x],v[x]),x));
	totv-=getVal(b[x],a[x]+b[x],v[x]);
	--b[x];
	sadd.insert(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	if(b[x])srem.insert(MP(getVal(b[x],a[x]+b[x],v[x]),x));
}

inline void addId(int x){
	sadd.erase(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	srem.erase(MP(getVal(b[x],a[x]+b[x],v[x]),x));
	++b[x];
	totv+=getVal(b[x],a[x]+b[x],v[x]);
	if(b[x]!=a[x])sadd.insert(MP(getVal(b[x]+1,a[x]+b[x]+1,v[x]),x));
	srem.insert(MP(getVal(b[x],a[x]+b[x],v[x]),x));
}

int n,m,q;

int main(){
	scanf("%d%d%d",&n,&m,&q);
	REP_1(i,n) scanf("%d",v+i);
	REP_1(i,n) scanf("%d",a+i),sadd.insert(MP(getVal(1,a[i]+1,v[i]),i));
	while(sadd.size()&&cnt<m){
		addId(sadd.rbegin()->Y);
		++cnt;
	}
	REP_1(i,q){
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1) changeA(x,1);
		else changeA(x,-1);
		while(sadd.size()&&srem.size()&&sadd.rbegin()->X>srem.begin()->X){
			int aa=sadd.rbegin()->Y;
			int bb=srem.begin()->Y;
			addId(aa);
			removeId(bb);
		}
		while(sadd.size()&&cnt<m){
			addId(sadd.rbegin()->Y);
			++cnt;
		}
		printf("%.10f\n",(double)totv);
	}
	return 0;
}