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

int fa[100100],dif[100100];
int cnt1[101001];
int cnt0[101001];
int getfa(int x){
	if(x==fa[x]) return x;
	getfa(fa[x]);
	dif[x]^=dif[fa[x]];
	return fa[x]=fa[fa[x]];
}

int n,m,ans;

vector<pair<int,int> > E[2];

vector<int> anss;

void solve(vector<PII> &Fr,vector<PII> &En){
	for(int i=1;i<=n;++i) fa[i]=i,dif[i]=0,cnt0[i]=cnt1[i]=0;
	for(int i=0;i<int(Fr.size());++i){
		int x=Fr[i].X,y=Fr[i].Y;
		int nd=0;
		getfa(x),getfa(y);
		nd^=dif[x]^dif[y];
		x=fa[x],y=fa[y];
		if(x==y){
			if(nd) return;
		}
		else{
			fa[x]=y;
			dif[x]=nd;
		}
	}
	for(int i=0;i<int(En.size());++i){
		int x=En[i].X,y=En[i].Y;
		int nd=1;
		getfa(x),getfa(y);
		nd^=dif[x]^dif[y];
		x=fa[x],y=fa[y];
		if(x==y){
			if(nd) return;
		}
		else{
			fa[x]=y;
			dif[x]=nd;
		}
	}
	for(int i=1;i<=n;++i){
		getfa(i);
		if(dif[i]) ++cnt1[fa[i]];
		else ++cnt0[fa[i]];
	}
	vector<int> tmp;
	for(int i=1;i<=n;++i){
		if(cnt0[fa[i]]<=cnt1[fa[i]]&&dif[i]==0||cnt0[fa[i]]>cnt1[fa[i]]&&dif[i]==1){
			tmp.PB(i);
		}
	}
	if((int)tmp.size()<ans) ans=tmp.size(),swap(anss,tmp);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		static char s[10];
		scanf("%d%d%s",&x,&y,s);
		E[s[0]=='B'].PB(MP(x,y));
	}
	ans=m+1;
	solve(E[0],E[1]);
	solve(E[1],E[0]);
	if(ans>m) printf("-1\n");
	else{
		printf("%d\n",ans);
		for(int i=0;i<int(anss.size());++i) printf("%d%c",anss[i],i==ans-1?'\n':' ');
	}
	scanf("%d",&n);
	return 0;
}