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

int dp[201][201][201],n,m,l;
char s1[201],s2[201],s3[201];
int nxt[201];
int f[201][26];
PIII pre[201][201][201];
void print(int x,int y,int z){
	if(!x&&!y&&!z) return;
	int fx=pre[x][y][z].X,fy=pre[x][y][z].Y.X,fz=pre[x][y][z].Y.Y;
	print(fx,fy,fz);
	if((x-fx)+(y-fy)==2)
	{
		putchar(s1[x]);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>(s1+1)>>(s2+1)>>(s3+1);
	n=strlen(s1+1),m=strlen(s2+1),l=strlen(s3+1);
	for(int i=2;i<=l;++i)
	{
		int j=nxt[i-1];
		while(j&&s3[j+1]!=s3[i]) j=nxt[j];
		nxt[i]=s3[j+1]==s3[i]?j+1:0;
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) for(int k=0;k<l;++k) if(dp[i][j][k]>=0)
	{
		if(s1[i+1]==s2[j+1])
		{
			int ff=k;
			while(ff&&s3[ff+1]!=s1[i+1]) ff=nxt[ff];
			if(dp[i+1][j+1][s3[ff+1]==s1[i+1]?ff+1:0]<dp[i][j][k]+1)
			{
				dp[i+1][j+1][s3[ff+1]==s1[i+1]?ff+1:0]=dp[i][j][k]+1;
				pre[i+1][j+1][s3[ff+1]==s1[i+1]?ff+1:0]=MP(i,MP(j,k));
			}
		}
		if(dp[i+1][j][k]<dp[i][j][k])
		{
			dp[i+1][j][k]=dp[i][j][k];
			pre[i+1][j][k]=MP(i,MP(j,k));
		}
		if(dp[i][j+1][k]<dp[i][j][k])
		{
			dp[i][j+1][k]=dp[i][j][k];
			pre[i][j+1][k]=MP(i,MP(j,k));
		}
	}
	int ans=0,nx=0,ny=0,nz=0;
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j) for(int k=0;k<l;++k)
	{
		if(ans<dp[i][j][k])
		{
			nx=i,ny=j,nz=k;
			ans=dp[i][j][k];
		}
	}
	if(ans==0) printf("0\n");
	else print(nx,ny,nz),printf("\n");
	cin>>s1;
	return 0;
}