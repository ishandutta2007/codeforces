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

namespace suffixArray{
	const int MAX_N=1600001;
	int rank[MAX_N],height[MAX_N];
	int sa[MAX_N];
	int cmp(int *x,int a,int b,int d){
		return x[a]==x[b]&&x[a+d]==x[b+d];
	}
	void doubling(int *a,int N,int M){
		static int sRank[MAX_N],tmpA[MAX_N],tmpB[MAX_N];
		int *x=tmpA,*y=tmpB;
		for(int i=0;i<M;++i) sRank[i]=0;
		for(int i=0;i<N;++i) ++sRank[x[i]=a[i]];
		for(int i=1;i<M;++i) sRank[i]+=sRank[i-1];
		for(int i=N-1;i>=0;--i) sa[--sRank[x[i]]]=i;
		for(int d=1,p=0;p<N;M=p,d<<=1){
			p=0; for(int i=N-d;i<N;++i) y[p++]=i;
			for(int i=0;i<N;++i) if(sa[i]>=d) y[p++]=sa[i]-d;
			for(int i=0;i<M;++i) sRank[i]=0;
			for(int i=0;i<N;++i) ++sRank[x[i]];
			for(int i=1;i<M;++i) sRank[i]+=sRank[i-1];
			for(int i=N-1;i>=0;--i) sa[--sRank[x[y[i]]]]=y[i];
			swap(x,y); x[sa[0]]=0; p=1;
			for(int i=1;i<N;++i) x[sa[i]]=cmp(y,sa[i],sa[i-1],d)?p-1:p++;
		}
	}
	void calcHeight(int *a,int N){
		for(int i=0;i<N;++i) rank[sa[i]]=i,height[i]=0;
		int cur=0; for(int i=0;i<N;++i)
		if(rank[i]){
			if(cur) cur--;
			for(;a[i+cur]==a[sa[rank[i]-1]+cur];++cur);
			height[rank[i]]=cur;
		}
	}
}

int RMQ[1600001][22];

int rec[1600001];

char s[1600001];

int v,n,m;

int Log2[1600001];

inline int getHeight(int x,int y){
	x=suffixArray::rank[x],y=suffixArray::rank[y];
	if(x>y) swap(x,y);
	int z=Log2[y-x];
	return min(RMQ[x][z],RMQ[y-(1<<z)][z]);
}

int st[200001];

int toLink[1600001];

struct Link{
	Link *pre,*nxt;
	int num;
	void init(Link *pre,Link *nxt,int num){
		this->pre=pre;
		this->nxt=nxt;
		this->num=num;
		pre->nxt=nxt->pre=this;
	}
	void remove(){
		pre->nxt=nxt;
		nxt->pre=pre;
	}
}L[200001],Head,Tail;

bool used[200001];

PQ<pair<int,pair<int,int> > > Q;

vector<PII> ans;
int anss;

int main(){
	REP_1(i,1600000){
		Log2[i]=i==1?0:Log2[i>>1]+1;
	}
	scanf("%d",&n);
	REP_1(i,2*n){
		scanf("%s",s);
		st[i]=v;
		for(int j=0;s[j];++j){
			rec[v++]=s[j]+2*n+1;
		}
		rec[v++]=2*n-i;
	}
	suffixArray::doubling(rec,v,2*n+300);
	suffixArray::calcHeight(rec,v);
	REP_0(i,v) RMQ[i][0]=suffixArray::height[i+1];
	REP_1(i,21){
		REP_0(j,v-(1<<i)){
			RMQ[j][i]=min(RMQ[j][i-1],RMQ[j+(1<<(i-1))][i-1]);
		}
	}
	REP_1(i,2*n){
		toLink[suffixArray::rank[st[i]]]=i;
	}
	Head.init(&Tail,&Tail,-1);
	Tail.init(&Head,&Head,-1);
	REP_0(i,v){
		if(toLink[i]){
			L[toLink[i]].init(Tail.pre,&Tail,toLink[i]);
		}
	}
	REP_1(i,n){
		if(L[i].pre->num>n){
			Q.push(make_pair(getHeight(st[i],st[L[i].pre->num]),MP(i,L[i].pre->num)));
		}
		if(L[i].nxt->num>n){
			Q.push(make_pair(getHeight(st[i],st[L[i].nxt->num]),MP(i,L[i].nxt->num)));
		}
	}
	while(!Q.empty()){
		pair<int,PII> ttop=Q.top();
		Q.pop();
		int x=ttop.second.first;
		int y=ttop.second.second;
		if(used[x]) continue;
		if(used[y]) continue;
		used[x]=used[y]=1;
		L[x].remove(),L[y].remove();
		anss+=ttop.first;
		ans.push_back(MP(x,y-n));
		if(L[y].pre->num!=-1&&L[y].nxt->num!=-1){
			int z=L[y].pre->num,w=L[y].nxt->num;
			if(z>w) swap(z,w);
			if(z<=n&&w>n){
				Q.push(MP(getHeight(st[z],st[w]),MP(z,w)));
			}
		}
	}
	printf("%d\n",anss);
	REP_0(i,n){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	scanf("%d",&n);
	return 0;
}