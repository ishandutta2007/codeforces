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
	void init(const int _S,const int _T);
}E[201001],*V[101001],*PE;
void EDGE::init(const int _S,const int _T){
	T=_T,Nxt=V[_S],V[_S]=this;
}
vector<PII> query[101000];
int ans[101000];
map<int,int> M[20];
int c[20][101001];
int color[101001];
int size[101000];
stack<int> unuse;
int n,m;
bool in[101000];
void dfs(int x){
	size[x]=1;
	in[x]=1;
	for(EDGE *ii=V[x];ii;ii=ii->Nxt){
		if(!in[ii->T]) dfs(ii->T),size[x]+=size[ii->T];
	}
}
inline void add(int x,int v,int *c){
	if(!x) return;
	while(x<=n){
		c[x]+=v;
		x+=x&-x;
	}
}
inline int sum(int x,int *c){
	int anss=0;
	while(x){
		anss+=c[x];
		x-=x&-x;
	}
	return anss;
}
void dfs2(int x,int belong){
	in[x]=0;    
	//if(V[x]){
	int maxnode=-1;
	for(EDGE *ii=V[x];ii;ii=ii->Nxt){
		if(in[ii->T]&&(maxnode==-1||size[ii->T]>size[maxnode])){
			maxnode=ii->T;
		}
	}
	if(maxnode!=-1){
		dfs2(maxnode, belong);
		for(EDGE *ii=V[x];ii;ii=ii->Nxt){
			if(in[ii->T]){
				int child=unuse.top();
				unuse.pop();
				dfs2(ii->T,child);
				for(map<int,int>::iterator iter=M[child].begin();iter!=M[child].end();++iter){
					add(iter->second,-1,c[child]);
					add(M[belong][iter->first],-1,c[belong]);
					M[belong][iter->first]+=iter->second;
					add(M[belong][iter->first],1,c[belong]);
				}
				M[child].clear();
				unuse.push(child);
			}
		}
	}
	add(M[belong][color[x]],-1,c[belong]);
	M[belong][color[x]]+=1;
	add(M[belong][color[x]],1,c[belong]);
	for(int i=0;i<int(query[x].size());++i){
		int y=query[x][i].first,z=query[x][i].second;
		ans[z]=sum(n,c[belong])-sum(min(y-1,n),c[belong]);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	for(int i=0;i<19;++i) unuse.push(i);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",color+i);
	}
	PE=E;
	for(int i=1;i<n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		PE++->init(x,y);
		PE++->init(y,x);
	}
	dfs(1);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		query[x].push_back(PII(y,i));
	}
	dfs2(1,19);
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	scanf("%d",&n);
	return 0;
}