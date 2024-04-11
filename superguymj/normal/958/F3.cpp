#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=200005,mod=1009;
const double pi=acos(-1);
int n,m,k,bin[N*3],len,a[N];
vector <LL> dat[N];

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
} A[N*3],B[N*3];

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

void solve(int l,int r)
{
	if(l==r)
	{
		rep(i,0,a[l]) dat[l].pb(1);
		return;
	}
	solve(l,mid),solve(mid+1,r);
	int sizl=dat[l].size()-1,sizr=dat[mid+1].size()-1;
	for(len=1; len<=sizl+sizr; len<<=1);
	rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
	rep(i,0,sizl) A[i]=(point){dat[l][i],0};
	rep(i,sizl+1,len-1) A[i]=(point){0,0};
	rep(i,0,sizr) B[i]=(point){dat[mid+1][i],0};
	rep(i,sizr+1,len-1) B[i]=(point){0,0};
	FFT(A,len,1),FFT(B,len,1);
	rep(i,0,len-1) A[i]=A[i]*B[i];
	FFT(A,len,-1),dat[l].clear();
	rep(i,0,sizl+sizr) dat[l].pb(((LL)(A[i].x+0.5))%mod);
}

int main()
{
	n=getint(),m=getint(),k=getint();
	rep(i,1,n) ++a[getint()];
	solve(1,m);
	printf("%lld\n",dat[1][k]);
	return 0;
}