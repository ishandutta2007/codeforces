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

int n,m,tot;

struct EDGE{
	int T;LL U;EDGE *Nxt,*Op;
	void init(const int S,const int T,const LL U,EDGE* const Op);
}*V[511],*FV[511],E[4111],*PE;

void EDGE::init(const int S,const int T,const LL U,EDGE* const Op){
	this->T=T;
	this->U=U;
	this->Op=Op;
	this->Nxt=V[S];
	V[S]=this;
}

vector<pair<int,PII> > EA;

long double L,R;

void addedge(int x,int y,long long z){
	PE->init(x,y,z,PE+1);
	++PE;
	PE->init(y,x,0,PE-1);
	++PE;
}

int S,T;

LL maxflow;

int dist[61];
const int inf=0x7f7f7f7f;

int Q[61],QH,QT;

inline bool modlabel(){
	REP_1(i,n) dist[i]=inf,FV[i]=V[i];
	dist[n]=0;
	QH=QT=-1;
	Q[++QT]=n;
	while(QH++!=QT){
		int x=Q[QH];
		for(EDGE *ii=V[x];ii;ii=ii->Nxt){
			if(ii->Op->U&&dist[ii->T]>dist[x]+1){
				dist[ii->T]=dist[x]+1;
				Q[++QT]=ii->T;
			}
		}
	}
	return dist[S]!=inf;
}

int aug(int x,int lim){
	if(x==T) return lim;
	int kk,ll=lim;
	for(EDGE *& ii=FV[x];ii;ii=ii->Nxt) if(ii->U&&dist[ii->T]+1==dist[x]){
		kk=aug(ii->T,min((long long)ll,ii->U));
		ll-=kk,ii->U-=kk,ii->Op->U+=kk;
		if(!ll) return lim;
	}
	return lim-ll;
}

bool solve(const LD &x){
	memset(V,0,sizeof(V));
	PE=E;
	for(int i=0;i<int(EA.size());++i){
		addedge(EA[i].X,EA[i].Y.X,LL(EA[i].Y.Y/x));
	}
	maxflow=0;
	while(modlabel()&&maxflow<tot){
		maxflow+=aug(S,tot);
	}
	return maxflow>=tot;
}

int main(){
	scanf("%d%d%d",&n,&m,&tot);
	S=1,T=n;
	REP_0(i,m){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		EA.PB(MP(x,MP(y,z)));
	}
	L=0,R=10000000;
	REP_0(tt,100){
		LD mid=(L+R)/2;
		if(solve(mid)){
			L=mid;
		}
		else R=mid;
	}
	cout<<fixed<<setprecision(20)<<(L+R)/2*tot<<endl;
	return 0;
}