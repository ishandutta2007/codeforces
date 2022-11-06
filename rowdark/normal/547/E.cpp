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

struct Query{
	int L,R,ID,S;
	Query(int L,int R,int ID,int S):L(L),R(R),ID(ID),S(S){}
};

int len[200001];
int st[500001];
char s[500001];
char ss[500001];
int n,q;
int gt[500001];
int rk[500001];
int sa[500001];
int H[22][500001];
int Qr[500001][2];
int ans[500001];

pair<pair<int,int>, int> FS[500001];

inline void SuffixArray(char *s,int N){
	for(int i=0;i<N;++i){
		FS[i].X.X=s[i],FS[i].X.Y=0;
		FS[i].Y=i;
	}
	sort(FS,FS+N);
	for(int i=0,j=-1;i<N;++i){
		if(i==0||FS[i].X!=FS[i-1].X){
			++j;
		}
		rk[FS[i].Y]=j;
	}
	for(int step=1;step<=N;step*=2){
		for(int i=0;i<N;++i){
			FS[i].X.X=rk[i];
			FS[i].X.Y=i+step<N?rk[i+step]:0;
			FS[i].Y=i;
		}
		sort(FS,FS+N);
		for(int i=0,j=-1;i<N;++i){
			if(i==0||FS[i].X!=FS[i-1].X){
				++j;
			}
			rk[FS[i].Y]=j;
		}
	}
	for(int i=0;i<N;++i){
		sa[rk[i]]=i;
	}
}

int lt[500001];
vector<Query> QQ[500001];
inline void add(int x){
	while(x<=500000) ++lt[x],x+=x&-x;
}
inline int getsum(int x){
	int ret=0;
	while(x){
		ret+=lt[x];
		x^=x&-x;
	}
	return ret;
}

int main(){
	char *eds=s;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		st[i]=eds-s;
		scanf("%s",ss);
		len[i]=strlen(ss);
		REP_0(j,len[i]) eds[j]=ss[j],gt[st[i]+j]=i;
		eds+=len[i]+1;
	}
	int totlen=eds-s;
	SuffixArray(s,totlen);
	for(int i=0,nw=0;i<totlen;++i){
		nw=max(0,nw-1);
		if(rk[i]!=totlen-1){
			int a=i;
			int b=sa[rk[i]+1];
			while(s[a+nw]==s[b+nw]) ++nw;
			H[0][rk[i]]=nw;
		}
	}
	for(int i=1;i<=20;++i){
		for(int j=0;j<totlen;++j){
			if(j+(1<<(i-1))<totlen){
				H[i][j]=min(H[i-1][j],H[i-1][j+(1<<(i-1))]);
			}
			else H[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i){
		int L=rk[st[i]],R=L;
		for(int j=20;j>=0;--j){
			if(L>=(1<<j)){
				if(H[j][L-(1<<j)]>=len[i]) L-=1<<j;
			}
			if(H[j][R]>=len[i]) R+=1<<j;
		}
		Qr[i][0]=L,Qr[i][1]=R;
	}
	for(int i=1;i<=q;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		QQ[Qr[c][1]].PB(Query(a,b,i,1));
		if(Qr[c][0]) QQ[Qr[c][0]-1].PB(Query(a,b,i,-1));
	}
	for(int i=0;i<totlen;++i){
		if(gt[sa[i]]){
			add(gt[sa[i]]);
		}
		for(int j=0;j<int(QQ[i].size());++j){
			ans[QQ[i][j].ID]+=QQ[i][j].S*(getsum(QQ[i][j].R)-getsum(QQ[i][j].L-1));
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	scanf("%d",&n);
	return 0;
}