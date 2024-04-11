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
	int T,U,V;EDGE *Nxt,*Op;
	void init(const int _S,const int _T,const int _U,const int _V,EDGE *_Op);
}E[6401*10],*V[6500],*PE;
bool in[6500];
int dist[6501];
void EDGE::init(const int _S,const int _T,const int _U,const int _V,EDGE *_Op){
	T=_T,U=_U,V=_V,Op=_Op,Nxt=::V[_S],::V[_S]=this;
}
int ans,S,T,maxflow;
bool modlabel(){
	int d=0x7fffffff;
	REP_0(i,T+1)
	{
		if(in[i])
		{
			for(EDGE *ii=V[i];ii;ii=ii->Nxt)
			{
				if(!in[ii->T]&&ii->U&&dist[ii->T]+ii->V-dist[i]<d)
				{
					d=dist[ii->T]+ii->V-dist[i];
				}
			}
		}
	}
	if(d==0x7fffffff) return false;
	REP_0(i,T+1) if(in[i]) dist[i]+=d;
	return true;
}
int aug(int p,int limit){
	if(p==T) return ans+=limit*dist[S],maxflow+=limit,limit;
	in[p]=1;
	EDGE *ii=V[p];
	int kk,ll=limit;
	while(ii)
	{
		if(!in[ii->T]&&ii->U&&ii->V+dist[ii->T]==dist[p])
		{
			kk=aug(ii->T,min(limit,ii->U));
			ll-=kk,ii->U-=kk,ii->Op->U+=kk;
			if(!ll) return in[p]=0,limit;
		}
		ii=ii->Nxt;
	}
	return limit-ll;
}
int f[81][81],n,m;

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n>>m;
	S=n*m,T=n*m+1,PE=E;
	REP_0(i,n) REP_0(j,m) cin>>f[i][j];
	REP_0(i,n) REP_0(j,m)
	{
		if(i!=n-1)
		{
			if(f[i][j]==f[i+1][j])
			{
				PE->init(i*m+j,(i+1)*m+j,((i+j)&1)?0:1,0,PE+1),++PE;
				PE->init((i+1)*m+j,i*m+j,((i+j)&1)?1:0,0,PE-1),++PE;
			}
			else
			{
				PE->init(i*m+j,(i+1)*m+j,((i+j)&1)?0:1,((i+j)&1)?-1:1,PE+1),++PE;
				PE->init((i+1)*m+j,i*m+j,((i+j)&1)?1:0,((i+j)&1)?1:-1,PE-1),++PE;
			}
		}
		if(j!=m-1)
		{
			if(f[i][j]==f[i][j+1])
			{
				PE->init(i*m+j,i*m+j+1,((i+j)&1)?0:1,0,PE+1),++PE;
				PE->init(i*m+j+1,i*m+j,((i+j)&1)?1:0,0,PE-1),++PE;
			}
			else
			{
				PE->init(i*m+j,i*m+j+1,((i+j)&1)?0:1,((i+j)&1)?-1:1,PE+1),++PE;
				PE->init(i*m+j+1,i*m+j,((i+j)&1)?1:0,((i+j)&1)?1:-1,PE-1),++PE;
			}
		}
		if((i+j)&1)
		{
			PE->init(i*m+j,T,1,0,PE+1),++PE;
			PE->init(T,i*m+j,0,0,PE-1),++PE;
		}
		else
		{
			PE->init(i*m+j,S,0,0,PE+1),++PE;
			PE->init(S,i*m+j,1,0,PE-1),++PE;
		}
	}
	do
	{
		do
		{
			memset(in,0,sizeof(in));
		}while(aug(S,2147483647));
	}while(modlabel());
	cout<<ans<<endl;
	cin>>n;
	return 0;
}