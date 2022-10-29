#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const double pi=acos(-1);
int n,k,x,mx,len,bin[9100000];
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
} a[9100000],f[9100000];

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
	if(tp==-1) rep(i,0,len-1) a[i].x/=len;
}

int main()
{
	n=getint(),k=getint(),f[0].x=1;
	rep(i,1,n) x=getint(),mx=max(x,mx),a[x].x=1;
	while(k)
	{
		for(len=1; len<=mx*2; len<<=1);
		if(k&1)
		{
			FFT(f,len,1),FFT(a,len,1);
			rep(i,0,len-1) f[i]=f[i]*a[i];
			FFT(f,len,-1);
			rep(i,0,len-1) f[i]=(point){(bool)((int)(f[i].x+0.5)),0};
		}
		else FFT(a,len,1);
		rep(i,0,len-1) a[i]=a[i]*a[i];
		FFT(a,len,-1);
		rep(i,0,len-1) a[i]=(point){(bool)((int)(a[i].x+0.5)),0};
		k>>=1,mx<<=1;
	}
	rep(i,0,mx)
	{
		int x=(int)(f[i].x+0.5);
		if(x) printf("%d ",i);
	}
	puts("");
	return 0;
}