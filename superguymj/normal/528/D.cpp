#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005;
const double pi=acos(-1);
typedef long long LL;
char s[N],t[N];
int n,m,ans[N],rt,k,len,bin[N<<2],S[N],T[N];
struct point
{
	double x,y;
	point operator + (point a)
	{
		return (point){x+a.x,y+a.y};
	}
	point operator - (point a)
	{
		return (point){x-a.x,y-a.y};
	}
	point operator * (point a)
	{
		return (point){x*a.x-y*a.y,x*a.y+y*a.x};
	}
} a[N<<2],b[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void FFT(point a[],int len,int tp)
{
	rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
	for(int i=1; i<len; i<<=1)
	{
		point wn=(point){cos(pi/i),tp*sin(pi/i)};
		for(int j=0; j<len; j+=i<<1)
		{
			point w=(point){1,0},x,y;
			rep(k,0,i-1)
			{
				x=a[j+k],y=a[i+j+k]*w,w=w*wn;
				a[j+k]=x+y,a[i+j+k]=x-y;
			}
		}
	}
	if(tp==-1) rep(i,0,len-1) a[i].x/=len;
}

void solve(int c)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int r=0;
	rep(i,0,n-1)
		if(S[i]==c)
		{
			rep(j,max(r,i-k),min(n-1,i+k)) a[j].x=1;
			r=i+k+1;
		}
	rep(i,0,m-1) if(T[i]==c) b[m-1-i].x=1;
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i];
	FFT(a,len,-1);
	rep(i,0,n-1) ans[i]+=(int)(a[i+m-1].x+0.5);
}

int main()
{
	n=getint(),m=getint(),k=getint();
	scanf("%s%s",s,t);
	rep(i,0,n-1)
	{
		if(s[i]=='A') S[i]=0;
		if(s[i]=='T') S[i]=1;
		if(s[i]=='C') S[i]=2;
		if(s[i]=='G') S[i]=3;
	}
	rep(i,0,m-1)
	{
		if(t[i]=='A') T[i]=0;
		if(t[i]=='T') T[i]=1;
		if(t[i]=='C') T[i]=2;
		if(t[i]=='G') T[i]=3;
	}
	for(len=1; len<=n+m-2; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	rep(i,0,3) solve(i);
	rep(i,0,n-m) if(ans[i]==m) ++rt;
	printf("%d\n",rt);
	return 0;
}