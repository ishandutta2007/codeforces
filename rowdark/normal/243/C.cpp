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
#define FOREACH(a,b) for(typeof(b.begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof(b.rbegin()) a=(b).rbegin();a!=b.rend();++a)
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

struct EDGE{
	int T;EDGE *Nxt;
};

template<class T>
void UpdataMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdataMax(T &x,T y){
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
	char buff[MaxBuffer];
	char *buf;
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
	}
	template<class T>
	bool readInterger(T &x)
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

bool F[3001][3001];
bool H[3001][3001];
VI X,Y;

const int maxn=2000000000;

char s[1011][21];
int a[1011],n;

void Filled(int x,int y,int z,int w){
	x=LB(X.begin(),X.end(),x)-X.begin();
	z=LB(X.begin(),X.end(),z)-X.begin();
	y=LB(Y.begin(),Y.end(),y)-Y.begin();
	w=LB(Y.begin(),Y.end(),w)-Y.begin();
	if(x>z) swap(x,z);
	if(y>w) swap(y,w);
//	cout<<x<<' '<<y<<' '<<z<<' '<<w<<endl;
	for(int i=x;i<=z;++i) for(int j=y;j<=w;++j) H[i][j]=1;
}

PII B[3001*3001];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

void Bfs(){
	int BH=-1,BT=4;
	B[0]=MP(0,0);
	B[1]=MP(X.size()-1,0);
	B[2]=MP(X.size()-1,Y.size()-1);
	B[3]=MP(0,Y.size()-1);
	F[0][0]=F[X.size()-1][0]=F[X.size()-1][Y.size()-1]=F[0][Y.size()-1]=1;
	while(BH++!=BT)
	{
		int nx=B[BH].X,ny=B[BH].Y;
		int fx,fy;
		for(int i=0;i<4;++i)
		{
			fx=nx+dx[i],fy=ny+dy[i];
			if(fx>-1&&fy>-1&&fx<int(X.size())&&fy<int(Y.size())&&!F[fx][fy]&&!H[fx][fy])
			{
				F[fx][fy]=1;
				B[++BT]=MP(fx,fy);
			}
		}
	}
	long long ans=0;
	for(int i=0;i<int(X.size());++i)
	{
		for(int j=0;j<int(Y.size());++j)
		{
			if(!F[i][j])
			{
				ans+=LL(X[i]-X[i-1])*(Y[j]-Y[j-1]);
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	X.PB(maxn),X.PB(-maxn);
	Y.PB(maxn),Y.PB(-maxn);
	cin>>n;
	REP_1(i,n) cin>>s[i]>>a[i];
	int nowx=0,nowy=0;
	X.PB(nowx),Y.PB(nowy);
	X.PB(nowx-1),Y.PB(nowy-1);
	REP_1(i,n)
	{
		if(s[i][0]=='U') nowx+=a[i];
		else if(s[i][0]=='D') nowx-=a[i];
		else if(s[i][0]=='L') nowy-=a[i];
		else if(s[i][0]=='R') nowy+=a[i];
		X.PB(nowx),Y.PB(nowy);
		X.PB(nowx-1),Y.PB(nowy-1);
	}
	sort(X.begin(),X.end());
	X.resize(unique(X.begin(),X.end())-X.begin());
//	for(int i=0;i<X.size();++i) cout<<X[i]<<endl;
	sort(Y.begin(),Y.end());
	Y.resize(unique(Y.begin(),Y.end())-Y.begin());
//	for(int i=0;i<Y.size();++i) cout<<Y[i]<<endl;
	nowx=0,nowy=0;
	int nx=0,ny=0;
	REP_1(i,n)
	{
		if(s[i][0]=='U') nx+=a[i];
		else if(s[i][0]=='D') nx-=a[i];
		else if(s[i][0]=='L') ny-=a[i];
		else if(s[i][0]=='R') ny+=a[i];
		Filled(nowx,nowy,nx,ny);
		nowx=nx,nowy=ny;
	}
	Bfs();
	return 0;
}