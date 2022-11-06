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

int n,m,q;

vector<int> V[200100];
vector<int> FV[200100];
int dfn[200100];
int low[200100];
int now;
bool vis[200100];
stack<int> S;
int nc[200100];
int fa[200100];

int ups[200100];
int downs[200100];
bool MMM[200100];

void tarjan(int x,int fa){
	dfn[x]=low[x]=++now;
	bool tf=false;
	vis[x]=1;
	S.push(x);
	REP_0(i,(int)V[x].size()){
		if(V[x][i]==fa&&!tf) tf=true;
		else{
			if(vis[V[x][i]]){
				low[x]=min(low[x],dfn[V[x][i]]);
			}
			else{
				tarjan(V[x][i],x);
				low[x]=min(low[x],low[V[x][i]]);
			}
		}
	}
	if(low[x]==dfn[x]){
		while(S.top()!=x){
			nc[S.top()]=dfn[x];
			S.pop();
		}
		nc[S.top()]=dfn[x];
		S.pop();
		MMM[dfn[x]]=1;
	}
}

int Lca[200100];
int getLca(const int x){
	if(x==Lca[x]) return x;
	else return Lca[x]=getLca(Lca[x]);
}

vector<PII> Interval[200100];

bool dfs(int x,int fa){
	vis[x]=1;
	REP_0(i,int(Interval[x].size())){
		if(vis[Interval[x][i].X]){
			int lca=getLca(Interval[x][i].X);
			--ups[lca];
			--downs[lca];
		}
		if(Interval[x][i].Y==1) ++ups[x];
		else ++downs[x];
	}
	REP_0(i,int(FV[x].size())){
		if(!dfs(FV[x][i],x)) return false;
		ups[x]+=ups[FV[x][i]];
		downs[x]+=downs[FV[x][i]];
		Lca[FV[x][i]]=x;
	}
	if(fa==-1&&(ups[x]||downs[x])) return false;
	if(ups[x]&&downs[x]) return false;
	return true;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		V[x].PB(y),V[y].PB(x);
	}
	REP_1(i,n) if(!vis[i]){
		tarjan(i,-1);
	}
	REP_1(i,n){
		REP_0(j,int(V[i].size())) if(nc[i]<nc[V[i][j]]){
			FV[nc[i]].PB(nc[V[i][j]]);
		}
	}
	memset(vis,0,sizeof(vis));
	REP_1(i,n) Lca[i]=i;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=nc[x];
		y=nc[y];
		if(x==y) continue;
		Interval[x].PB(MP(y,1));
		Interval[y].PB(MP(x,-1));
	}
	REP_1(i,n) if(MMM[i]&&!vis[i]){
		if(!dfs(i,-1)){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}