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
	int T,C;EDGE *Nxt;
	void init(const int _s,const int _t,const int _c);
}E[4002],*V[2001],*PE;
void EDGE::init(const int _s,const int _t,const int _c){
	T=_t,Nxt=V[_s],C=_c,V[_s]=this;
}
int N;
int D[2002][2002];

bool checkbasic(){
	REP_1(i,N) REP_1(j,i) if(D[i][j]!=D[j][i]) return false;
	REP_1(i,N) if(D[i][i]!=0) return false;
	REP_1(i,N) REP_1(j,N) if(i!=j&&D[i][j]==0) return false;
	return true;
}

bool in[2001];
int ND[2002],From[2002];

LL Dist[2002];

bool checknode(int x){
	Dist[x]=0;
	memset(in,0,sizeof(in));
	in[x]=1;
	queue<int> Q;
	Q.push(x);
	while(!Q.empty()){
		int y=Q.front();
		Q.pop();
		for(EDGE *ii=V[y];ii;ii=ii->Nxt) if(!in[ii->T]){
			Dist[ii->T]=Dist[y]+ii->C;
			in[ii->T]=1;
			Q.push(ii->T);
		}
	}
	REP_1(i,N) if(D[x][i]!=Dist[i]) return false;
	return true;
}

bool checkalldist(){
	REP_1(i,N){
		if(!checknode(i)) return false;;
	}
	return true;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	PE=E;
	scanf("%d",&N);
	REP_1(i,N) REP_1(j,N) scanf("%d",D[i]+j);
	if(!checkbasic()){
		printf("NO\n");
		return 0;
	}
	memset(ND,127,sizeof(ND));
	memset(From,-1,sizeof(From));
	ND[1]=0;
	REP_1(tt,N){
		int ch=-1;
		REP_1(i,N) if(!in[i]) if(ch==-1||ND[i]<ND[ch]) ch=i;
		in[ch]=1;
		if(From[ch]!=-1) PE++->init(From[ch],ch,ND[ch]),PE++->init(ch,From[ch],ND[ch]);
		REP_1(i,N) if(!in[i]) if(D[ch][i]<ND[i]) ND[i]=D[ch][i],From[i]=ch;
	}
	printf("%s\n",checkalldist()?"YES":"NO");
	return 0;
}