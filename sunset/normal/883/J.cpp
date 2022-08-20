#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=100007;

int n,m,s[N],f[N],g,l[N];
ll q[N],u[N];
pii t[N];
std::priority_queue<int>h;

inline bool cmp(pii x,pii y)
{
	return x.yy<y.yy;
}

inline void modify(int x,ll v)
{
	for(;x<=g;x+=x&-x)u[x]+=v;
}

inline ll query(int x)
{
	ll r=0;
	static int tt=0;
	tt++;
	//if(tt%100==0||tt>31200)out,tt,' ',x,'\n';
	for(;x;x^=x&-x)r+=u[x];
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	in,n,m;
	fo1(i,n)in,s[i];
	fo1(i,m)in,t[i].xx;
	fo1(i,m)in,t[i].yy;
	std::sort(t+1,t+m+1);
	//fo1(i,m)out,t[i].xx,' ',t[i].yy,'\n';out,'\n';
	fo1(i,n)
	{
		for(;g&&s[f[g-1]]<=s[i];g--);
		f[g++]=i;
	}
	int lst=0;
	fo0(i,g)
	{
		fo(j,lst+1,f[i])q[i]+=s[j];
		lst=f[i];
		f[i]=s[f[i]];
	}
	fd0(i,g)f[i+1]=f[i];
	fd0(i,g)q[i+1]=q[i];
	//fo1(i,g)out,f[i],' ',q[i],'\n';
	lst=1;
	fd1(i,g)
	{
		for(;lst<=m&&t[lst].xx<=f[i];lst++)t[lst].xx=i;
	}
	for(;lst<=m;lst++)t[lst].xx=0;
	fo1(i,g)modify(i,q[i]);
	fo1(i,g)l[i]=i;
	std::sort(t+1,t+m+1,cmp);
	//fo1(i,m)out,t[i].xx,' ',t[i].yy,'\n';
	int ans=0;
	fo1(i,m)
	{
		int x=t[i].xx,y=t[i].yy;
		if(query(x)<y)continue;
		//out,'/',x,' ',y,'\n';
		ans++;
		while(y)
		{
			for(;l[x]!=x;x=l[x]=l[l[x]]);//if(i%100==0||i>=31200)out,i,' ',x,' ',l[x],'\n';
			if(q[x]>y)
			{
				modify(x,-y);
				q[x]-=y;
				y=0;
			}
			else
			{
				modify(x,-q[x]);
				y-=q[x];
				q[x]=0;
				x=l[x]=x-1;
			}
		}
	}
	out,ans,'\n';
}