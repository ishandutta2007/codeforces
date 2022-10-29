#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=200005;
const LL INF=100000000000000000;
int n,m,tot,stk[N];
LL a[N],f[N];
struct data{LL l,r;} dat[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool cmp(data a,data b)
{
	return a.r==b.r?a.l>b.l:a.r<b.r;
}

bool in(data a,data b)
{
	return b.l<=a.l && a.r<=b.r;
}

bool check(int L,int R)
{
	int l=1,r=n;
	while(l<=r) a[mid]>=L?r=mid-1:l=mid+1;
	++r;
	if(r>n) return 0;
	if(a[r]>R) return 0;
	return 1;
}

void solve()
{
	n=getint(),m=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n),a[0]=-INF,a[n+1]=INF;
	rep(i,1,m) dat[i].l=getint(),dat[i].r=getint();
	sort(dat+1,dat+1+m,cmp);
	tot=0;
	rep(i,1,m)
	{
		if(check(dat[i].l,dat[i].r)) continue;
		if(tot && in(dat[stk[tot]],dat[i])) continue;
		while(tot && in(dat[i],dat[stk[tot]])) --tot;
		stk[++tot]=i;
	}
	rep(i,1,tot) dat[i]=dat[stk[i]];
	m=tot;
	rep(i,1,m) f[i]=INF;
	rep(i,1,n)
	{
		int l=1,r=m;
		while(l<=r) dat[mid].l>a[i]?r=mid-1:l=mid+1;
		int x=r+1;
		LL y1=f[x-1],y2=f[x-1];
		repd(j,x-1,1)
		{
			if(dat[j].r<a[i-1]) break;
			y1=min(y1,f[j-1]+a[i]-dat[j].r);
			y2=min(y2,f[j-1]+(a[i]-dat[j].r)*2);
			f[x-1]=min(f[x-1],f[j-1]+a[i]-dat[j].r);
		}
		rep(j,x,m)
		{
			if(dat[j].l>a[i+1]) break;
			f[j]=min(f[j],y1+(dat[j].l-a[i])*2);
			f[j]=min(f[j],y2+(dat[j].l-a[i]));
		}
	}
	printf("%lld\n",f[m]);
}

int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}