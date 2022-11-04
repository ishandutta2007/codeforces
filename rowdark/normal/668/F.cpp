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

map<int,int> OPTS;
int ROP[203];
int CH[203][203];
vector<PII> Ex[203];
int fa[6];
int N,M;
int f[10001][6];
int dp[10001][203];
int CHA[203][6];
const unsigned long long toMod=17446744057709551552ULL;
unsigned long long H[203];
unsigned long long v[203];
const int mod=1000000007;
vector<int> E[10010];
int cnts;

bool Basic[203];

inline int Change(int o,int c){
	static int f[10];
	for(int i=1;i<=M+1;++i){
		f[i]=o%10;
		o/=10;
	}
	if(f[M+1]==M+1) return -1;
	for(int i=M;i>=c;--i){
		f[i+1]=f[i]+(f[i]>=c);
	}
	f[c]=c;
	for(int i=M+1;i>=1;--i){
		o=o*10+f[i];
	}
	return OPTS[o];
}

inline int Compress(){
	int v=0;
	for(int i=M+1;i>=1;--i){
		int f=i;
		for(int j=i-1;j>=0;--j) if(fa[i]==fa[j]){
			f=j;
		}
		v=v*10+f;
	}
	return v;
}

int getfa(int x,int fa[]){
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x],fa);
}

inline int Union(int Opt1,int Opt2){
	static int lfa[10];
	for(int i=1;i<=M+1;++i){
		lfa[i]=Opt1%10;
		Opt1/=10;
	}
	for(int i=1;i<=M+1;++i){
		int oo=Opt2%10;
		int g=getfa(oo,lfa);
		int f=getfa(i,lfa);
		if(f!=g){
			lfa[max(f,g)]=min(f,g);
		}
		else{
			if(oo!=i) return -1;
		}
		Opt2/=10;
	}
	for(int i=1;i<=M+1;++i) getfa(i,lfa);
	for(int i=M+1;i>=1;--i){
		Opt1=Opt1*10+lfa[i];
	}
	return OPTS[Opt1];
}

inline bool check(){
	int f=1;
	for(int i=1;i<M+1;++i) if(fa[i]!=f) for(int j=1;j<i;++j) if(fa[i]==fa[j]){
		return false;
	}
	return true;
}

void getROP(int x,int s){
	if(!x){
		ROP[cnts]=Compress();
		OPTS[ROP[cnts]]=cnts;
		Basic[cnts]=check();
		++cnts;
		return;
	}
	for(int i=1;i<=s+1;++i){
		fa[x]=i;
		getROP(x-1,s+(s+1==i));
	}
}

inline void Add(unsigned long long &x,const unsigned long long &y){
	x+=y;
	if(x>=toMod) x%=mod;
}

void dfs(int x){
	for(int i=0;i<cnts;++i) dp[x][i]=Basic[i];
	REP_0(ii,int(E[x].size())){
		int y=E[x][ii];
		dfs(y);
		{
			int g=1;
			while(g<=M&&f[x][g]==f[y][g]) ++g;
			REP_0(i,cnts) v[i]=0;
			REP_0(i,cnts){
				if(CHA[i][g]!=-1){
					v[CHA[i][g]]+=dp[y][i];
				}
			}
			REP_0(i,cnts) v[i]%=mod;
		}
		REP_0(i,cnts) if(dp[x][i]) REP_0(j,int(Ex[i].size())) if(v[Ex[i][j].X]){
			Add(H[Ex[i][j].Y],dp[x][i]*v[Ex[i][j].X]);
		}
		REP_0(i,cnts){
			dp[x][i]=H[i]%mod;
			H[i]=0;
		}
	}
}

int FCC[10];

unsigned long long Mat[10][10];

unsigned long long calcDet(int n){
	memset(Mat,0,sizeof(Mat));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) if(i!=j){
			Mat[i][j]=(Mat[i][j]-FCC[i]*FCC[j]+mod)%mod;
			Mat[i][i]=(Mat[i][i]+FCC[i]*FCC[j])%mod;
		}
	}
	unsigned long long ret=1;
	for(int i=1;i<n;++i){
		for(int j=i;j<n;++j){
			if(Mat[j][i]!=0){
				for(int k=i;k<n;++k){
					swap(Mat[i][k],Mat[j][k]);
				}
				if(j!=i){
					ret=(mod-ret)%mod;
				}
				break;
			}
		}
		if(!Mat[i][i]) return 0;
		ret=ret*Mat[i][i]%mod;
		{
			int f=Pow((int)Mat[i][i],mod-2,mod);
			for(int j=i;j<n;++j) Mat[i][j]=Mat[i][j]*f%mod;
		}
		for(int j=i+1;j<n;++j) if(Mat[j][i]){
			int f=Mat[j][i];
			for(int k=i;k<n;++k){
				Mat[j][k]=(Mat[j][k]-Mat[i][k]*f%mod+mod)%mod;
			}
		}
	}
	return ret;
}

unsigned long long calcAns(int Op){
	static int f[10];
	REP_1(i,M+1) f[i]=Op%10,Op/=10;
	if(f[M+1]==M+1) return 0;
	for(int i=2;i<=M+1;++i) if(f[i]==1) return 0;
	memset(FCC,0,sizeof(FCC));
	for(int i=2;i<=M;++i) ++FCC[f[i]];
	int lt=0;
	for(int i=2;i<=M;++i){
		if(FCC[i]) FCC[++lt]=FCC[i];
	}
	return calcDet(lt);
}

int main(){
	scanf("%d%d",&N,&M);
	if(M==1){
		printf("1\n");
		return 0;
	}
	getROP(M+1,0);
	REP_0(i,cnts){
		REP_0(j,i){
			CH[i][j]=CH[j][i]=Union(ROP[i],ROP[j]);
		}
		CH[i][i]=Union(ROP[i],ROP[i]);
	}
	REP_0(i,cnts){
		REP_1(j,M+1){
			CHA[i][j]=Change(ROP[i],j);
		}
	}
	REP_0(i,cnts){
		REP_0(j,cnts){
			if(CH[i][j]!=-1){
				Ex[i].PB(MP(j,CH[i][j]));
			}
		}
	}
	REP_3(i,M+1,N){
		REP_1(j,M){
			scanf("%d",f[i]+j);
		}
		sort(f[i]+1,f[i]+M+1);
		E[f[i][M]].push_back(i);
	}
	REP_1(i,M) f[M][i]=i-1;
	dfs(M);
	unsigned long long ans=0;;
	REP_0(i,cnts) if(dp[M][i]){
		ans+=dp[M][i]*calcAns(ROP[i]);
	}
	cout<<ans%mod<<endl;
	cin>>N;
	return 0;
}