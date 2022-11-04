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
const int MAX_N=501000;

namespace SA{
	int sa[MAX_N];
	int rank[MAX_N],height[MAX_N];

	int sRank[MAX_N],tmpA[MAX_N],tmpB[MAX_N];
	int cmp(int *x,int a,int b,int d){
		return x[a]==x[b]&&x[a+d]==x[b+d];
	}
	void doubling(int *a,int N,int M){
		int *x=tmpA,*y=tmpB;
		for(int i=0;i<M;++i) sRank[i]=0;
		for(int i=0;i<N;++i) ++sRank[x[i]=a[i]];
		for(int i=1;i<M;++i) sRank[i]+=sRank[i-1];
		for(int i=N-1;i>=0;--i) sa[--sRank[x[i]]]=i;
		for(int d=1,p=0;d<N;M=p,d<<=1){
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
	void calcHeight(int *a, int N){
		for(int i=0;i<N;++i) rank[sa[i]]=i;
		int cur=0; for(int i=0;i<N;++i)
		if(rank[i]){
			if(cur) cur--;
			for(;a[i+cur]==a[sa[rank[i]-1]+cur];++cur);
			height[rank[i]]=cur;
		}
	}
}
int n;
char s[500101];
int A[500101];
vector<int> nadd[500101];

int lt[1048580];

inline void insert(int x,int v){
	x+=524288;
	while(x) lt[x]=min(lt[x],v),x>>=1;
}

inline int getmin(int l,int r){
	l+=524288-1,r+=524288+1;
	int ret=lt[0];
	while(l^r^1){
		if(~l&1) ret=min(ret,lt[l^1]);
		if(r&1) ret=min(ret,lt[r^1]);
		l>>=1,r>>=1;
	}
	return ret;
}

int Cnt[1001000];
int *cnt=Cnt+500100;

int Sum[1001000];
int *sum=Sum+1;

int main(){
	memset(lt,0x7f7f7f7f,sizeof(lt));
	scanf("%d%s",&n,s);
	REP_0(i,n){
		A[i]=s[i]=='('?1:2;
	}
	A[n]=0;
	SA::doubling(A,n+1,3);
	SA::calcHeight(A,n+1);
	REP_0(i,n){
		nadd[i+SA::height[SA::rank[i]]].push_back(i);
	}
	long long ans=0;
	REP_0(i,n){
		for(int j=0;j<int(nadd[i].size());++j){
			int y=nadd[i][j];
			if(getmin(y+1,i+1)>=sum[y-1]){
				++cnt[sum[y-1]];
			}
		}
		sum[i]+=A[i]==1?1:-1;
		insert(i+1,sum[i]);
		ans+=cnt[sum[i]];
		cnt[sum[i]+1]=0;
		sum[i+1]=sum[i];
	}
	cout<<ans<<endl;
	scanf("%d",&n);
	return 0;
}