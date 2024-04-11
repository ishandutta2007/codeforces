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

LL Pow(LL x,LL y,LL P){
	LL F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=F1*x%P;
		}
		x=x*x%P;
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

int D[201001];
int V[201001];
int Q;
int la;
const int Mod=1000000007;
VI C[201001];

struct Ops{
	int op;
	int a;
}O[300000];

long long lt[1048577];
int Lpos[200100];
int Rpos[200100];

inline long long getLt(int x){
	long long ret=1;
	while(x){
		ret*=lt[x];
		if(ret>=Mod) ret%=Mod;
		x^=x&-x;
	}
	return ret;
}

inline long long setLt(int x,int &y){
	long long v=Pow(y,Mod-2,Mod)*(y+1)%Mod;
	++y;
	int z=Lpos[x];
	while(z<1048576){
		lt[z]*=v;
		if(lt[z]>=Mod) lt[z]%=Mod;
		z+=z&-z;
	}
	long long vv=Pow(v,Mod-2,Mod);
	z=Rpos[x];
	while(z<1048576){
		lt[z]*=vv;
		if(lt[z]>=Mod) lt[z]%=Mod;
		z+=z&-z;
	}
	return v;
}

struct Tree{
	long long sum;
	long long mul;
	long long getSum(){
		return sum*mul%Mod;
	}
}T[1048577];

void add(int x,int l,int r,int now,int v){
	if(l==r){
		T[now].sum=v;
		return;
	}
	if(T[now].mul!=1){
		T[2*now].mul*=T[now].mul;
		if(T[2*now].mul>=Mod) T[2*now].mul%=Mod;
		T[2*now+1].mul*=T[now].mul;
		if(T[2*now+1].mul>=Mod) T[2*now+1].mul%=Mod;
		T[now].mul=1;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(x,l,mid,now*2,v);
	else add(x,mid+1,r,now*2+1,v);
	T[now].sum=T[2*now].getSum()+T[2*now+1].getSum();
	if(T[now].sum>=Mod) T[now].sum-=Mod;
}

void mul(int ll,int rr,int l,int r,int now,int v){
	if(l==ll&&r==rr){
		T[now].mul*=v;
		if(T[now].mul>=Mod) T[now].mul%=Mod;
		return;
	}
	if(T[now].mul!=1){
		T[2*now].mul*=T[now].mul;
		if(T[2*now].mul>=Mod) T[2*now].mul%=Mod;
		T[2*now+1].mul*=T[now].mul;
		if(T[2*now+1].mul>=Mod) T[2*now+1].mul%=Mod;
		T[now].mul=1;
	}
	int mid=(l+r)>>1;
	if(rr<=mid) mul(ll,rr,l,mid,now*2,v);
	else if(ll>mid) mul(ll,rr,mid+1,r,now*2+1,v);
	else mul(ll,mid,l,mid,now*2,v),mul(mid+1,rr,mid+1,r,now*2+1,v);
	T[now].sum=T[2*now].getSum()+T[2*now+1].getSum();
	if(T[now].sum>=Mod) T[now].sum-=Mod;
}

LL sum(int ll,int rr,int l,int r,int now){
	if(l==ll&&r==rr){
		return T[now].getSum();
	}
	if(T[now].mul!=1){
		T[now].sum*=T[now].mul;
		if(T[now].sum>=Mod) T[now].sum%=Mod;
		T[2*now].mul*=T[now].mul;
		if(T[2*now].mul>=Mod) T[2*now].mul%=Mod;
		T[2*now+1].mul*=T[now].mul;
		if(T[2*now+1].mul>=Mod) T[2*now+1].mul%=Mod;
		T[now].mul=1;
	}
	int mid=(l+r)>>1;
	if(rr<=mid) return sum(ll,rr,l,mid,now*2);
	else if(ll>mid) return sum(ll,rr,mid+1,r,now*2+1);
	else return (sum(ll,mid,l,mid,now*2)+sum(mid+1,rr,mid+1,r,now*2+1))%Mod;
}

void dfs(int x){
	Lpos[x]=++la;
	for(int i=0;i<int(C[x].size());++i) dfs(C[x][i]);
	Rpos[x]=++la;
}

int main(){
	scanf("%d%d",V+1,&Q);
	la=1;
	REP_1(i,Q){
		scanf("%d%d",&O[i].op,&O[i].a);
		if(O[i].op==1){
			++la;
			scanf("%d",V+la);
			C[O[i].a].PB(la);
		}
	}
	int N=la;
	REP_1(i,N) D[i]=1;
	la=0;
	dfs(1);
	for(int i=1;i<=1048576;++i) lt[i]=1,T[i].mul=1;
	N=la;
	la=1;
	add(Lpos[1],1,N,1,V[1]);
	REP_1(i,Q){
		if(O[i].op==1){
			++la;
			add(Lpos[la],1,N,1,V[la]);
			long long vv=setLt(O[i].a,D[O[i].a]);
			mul(Lpos[O[i].a],Rpos[O[i].a],1,N,1,vv);
		}
		else{
			printf("%d\n",(int)(sum(Lpos[O[i].a],Rpos[O[i].a],1,N,1)*Pow(getLt(Lpos[O[i].a]-1),Mod-2,Mod)%Mod));
		}
	}
	scanf("%d",&N);
	return 0;
}