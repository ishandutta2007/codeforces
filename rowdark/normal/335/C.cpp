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
T By(T x,T y,T P){
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
T Mul(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=By(F1,x,P);
		}
		x=By(x,x,P);
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

int dp[111][3][3];
bitset<601> B;
bool co[111][2];
int c[111][2];
//len=top-bot+1,x,y=0 for co 1 for l 2 for r
inline int getdp(int len,int x,int y){
	if(len<=0) return 0;
	if(len==1) x&=y,y=x;
	return dp[len][x][y];
}
void solve(int h,int top,int bot){
	B.reset();
	REP_1(i,h)
	{
		++c[i][0],++c[i][1];
		if(c[i][0]==1)
		{
			++c[i-1][1],++c[i+1][1];
			int f=getdp(i-1,3-((c[1][0]?1:0)+(c[1][1]?2:0)),3-((c[i-1][0]?1:0)+(c[i-1][1]?2:0)));
			f^=getdp(h-i,3-((c[i+1][0]?1:0)+(c[i+1][1]?2:0)),3-((c[h][0]?1:0)+(c[h][1]?2:0)));
//			cout<<f<<endl;
			if(f==-1)
			{
				puts("!!!");
				puts("!!!");
			}
			B[f]=1;
			--c[i-1][1],--c[i+1][1];
		}
		if(c[i][1]==1)
		{
			++c[i-1][0],++c[i+1][0];
			int f=getdp(i-1,3-((c[1][0]?1:0)+(c[1][1]?2:0)),3-((c[i-1][0]?1:0)+(c[i-1][1]?2:0)));
			f^=getdp(h-i,3-((c[i+1][0]?1:0)+(c[i+1][1]?2:0)),3-((c[h][0]?1:0)+(c[h][1]?2:0)));
//			cout<<f<<endl;
			if(f==-1)
			{
				puts("!!!");
				puts("!!!");
			}
			B[f]=1;
			--c[i-1][0],--c[i+1][0];
		}
		--c[i][0],--c[i][1];
	}
	dp[h][top][bot]=0;
	while(B[dp[h][top][bot]]) ++dp[h][top][bot];
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	dp[1][2][2]=dp[1][1][1]=1;
	REP_3(i,2,104)
	{
		REP_0(j,3)
		{
			REP_0(k,3)
			{
				c[1][0]=!(j&1);
				c[1][1]=!((j&2)>>1);
				c[i][0]=!(k&1);
				c[i][1]=!((k&2)>>1);
				solve(i,j,k);
				c[1][0]=c[1][1]=0;
				c[i][0]=c[i][1]=0;
			}
		}
	}
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		++c[x+1][y-1];
	}
	c[0][0]=c[0][1]=1;
	c[n+3][0]=c[n+3][1]=1;
	int pre=0;
	REP_1(i,n+3)
	{
		if(c[i][0]||c[i][1])
		{
			ans^=getdp(i-pre-1,3-(c[i][0]+(c[i][1]<<1)),3-(c[pre][0]+(c[pre][1]<<1)));
			pre=i;
		}
	}
	printf("%s\n",ans?"WIN":"LOSE");
	scanf("%d",&n);
	return 0;
}