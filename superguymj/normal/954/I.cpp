#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const double pi=acos(-1);
const int N=262144;
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
} f[N],a[6][N],b[6][N];
char s[N],t[N];
bool mp[6][6][N];
int n,m,bin[N],fa[6],len,ans;

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

int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

int main()
{
	scanf("%s%s",s,t);
	n=strlen(s),m=strlen(t);
	rep(i,0,n-1) a[s[i]-'a'][i].x=1;
	rep(i,0,m-1) b[t[i]-'a'][m-1-i].x=1;
	for(len=1; len<=n+m-2; len<<=1);
	rep(i,1,len-1) bin[i]=bin[i>>1]>>1|((len>>1)*(i&1));
	rep(i,0,5) FFT(a[i],len,1),FFT(b[i],len,1);
	rep(i,0,5) rep(j,0,5)
	{
		rep(k,0,len-1) f[k]=a[i][k]*b[j][k];
		FFT(f,len,-1);
		rep(k,0,n-m) mp[i][j][k]=(bool)((int)(f[k+m-1].x+0.5));
	}
	rep(i,0,n-m)
	{
		rep(j,0,5) fa[j]=j;
		ans=0;
		rep(j,0,5) rep(k,0,5) if(mp[j][k][i])
		{
			int x=getfa(j),y=getfa(k);
			if(x!=y) fa[x]=y,++ans;
		}
		printf("%d ",ans);
	}
	return puts(""),0;
}