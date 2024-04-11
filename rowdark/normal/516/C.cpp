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
struct node{
	LL d,sum,maxr,maxl,maxans;
	node():d(0),sum(0),maxr(0),maxl(0),maxans(0){}
	node(LL d,LL init):d(d),sum(0),maxr(init),maxl(init),maxans(init){}
	node Union(const node *that)const{
		node ret;
		ret.d=this->d;
		ret.sum=this->sum+that->d+that->sum;
		ret.maxr=max(this->maxr+that->sum+that->d,that->maxr);
		ret.maxl=max(this->maxl,this->sum+that->d+that->maxl);
		ret.maxans=max(this->maxr+that->maxl+that->d,max(this->maxans,that->maxans));
		return ret;
	}
};

node LT[524290];
int d[524290];
int h[524290];
void build(int l,int r,int now){
	if(l==r){
		LT[now]=node(d[l],h[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	LT[now]=LT[now*2].Union(LT+now*2+1);
}

int n,m;
bool first;

void Query(int l,int r,int ll,int rr,int now,node &ret){
	if(l==ll&&r==rr){
		if(first) ret=LT[now],first=false;
		else ret=ret.Union(LT+now);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=rr) Query(l,mid,ll,rr,now*2,ret);
	else if(mid<ll) Query(mid+1,r,ll,rr,now*2+1,ret);
	else Query(l,mid,ll,mid,now*2,ret),Query(mid+1,r,mid+1,rr,now*2+1,ret);
}

int main(){
	scanf("%d%d",&n,&m);
	REP_1(i,n) scanf("%d",d+i+1);
	REP_1(i,n) scanf("%d",h+i),h[i]*=2;
	d[1]=d[n+1];
	REP_1(i,n){
		d[i+n]=d[i];
		h[i+n]=h[i];
	}
	build(1,n*2,1);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		node ans;
		first=true;
		if(x<=y) Query(1,n*2,y+1,n+x-1,1,ans);
		else Query(1,n*2,y+1,x-1,1,ans);
		printf("%I64d\n",ans.maxans);
	}
	return 0;
}