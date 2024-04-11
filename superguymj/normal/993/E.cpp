#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
const double pi=acos(-1);
int n,lim,s[N],A[N];
int bin[N<<2],len;
typedef long long LL;

struct point
{
	double x,y;

	point operator + (point t)
	{
		return (point){x+t.x,y+t.y};
	}

	point operator - (point t)
	{
		return (point){x-t.x,y-t.y};
	}

	point operator * (point t)
	{
		return (point){x*t.x-y*t.y,x*t.y+y*t.x};
	}

	point operator / (int t)
	{
		return (point){x/t,y/t};
	}
} a[N<<2],b[N<<2];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void FFT(point a[],int len,int tp)
{
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
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
	if(tp==-1) rep(i,0,len-1) a[i]=a[i]/len;
}

int main()
{
	n=getint(),lim=getint();
	rep(i,1,n) s[i]=s[i-1]+(A[i]=(getint()<lim));
	rep(i,0,n-1) a[n-s[i]].x+=1;
	rep(i,1,n) b[s[i]].x+=1;
	for(len=1; len<=n*2; len<<=1);	
	FFT(a,len,1),FFT(b,len,1);
	rep(i,0,len-1) a[i]=a[i]*b[i];
	FFT(a,len,-1);
	LL ans=0,tmp=0;
	rep(i,1,n)
	{
		if(A[i]==0) ++tmp;
		else tmp=0;
		ans+=tmp;
	}
	printf("%lld",ans);
	rep(i,1,n)
	{
		LL x=(LL)(a[i+n].x+0.5);
		printf(" %lld",x);
	}
	puts("");
	return 0;
}