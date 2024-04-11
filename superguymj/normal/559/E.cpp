#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=105;
const int INF=2000000000;
typedef long long LL;
int n,tot,L[N],R[N];
LL pool[N<<1],f[N][N<<1],g[N][N<<1],ans;
struct data{int p,l,r;} dat[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int find(int x)
{
	int l=0,r=tot;
	while(l<=r) if(pool[mid]<=x) l=mid+1; else r=mid-1;
	return l-1;
}

bool cmp(data a,data b)
{
	return a.p<b.p;
}

int main()
{
	n=getint();
	rep(i,1,n)
	{
		dat[i].p=getint(),dat[i].l=dat[i].r=getint();
		pool[++tot]=dat[i].p,pool[++tot]=dat[i].p+dat[i].r;
	}
	sort(dat+1,dat+1+n,cmp);
	sort(pool+1,pool+1+tot);
	rep(i,1,tot) if(i==1 || pool[i]!=pool[i-1]) pool[++*pool]=pool[i];
	tot=*pool,*pool=-INF;

	rep(i,0,n) rep(j,0,tot) f[i][j]=-INF;
	f[0][0]=0;
	
	rep(i,1,n)
	{
		int x=find(dat[i].p+dat[i].r),p=find(dat[i].p);
		L[i]=find(dat[i].p-dat[i].l),R[i]=x;
		rep(j,0,tot)
		{
			if(x>j)
			{
				if(p>j) f[i][x]=max(f[i][x],f[i-1][j]+dat[i].r);
				else f[i][x]=max(f[i][x],f[i-1][j]+pool[x]-pool[j]);
			}
			else f[i][j]=max(f[i][j],f[i-1][j]);
		}

		g[i-1][tot]=f[i-1][tot]-pool[tot];
		repd(j,tot-1,0) g[i-1][j]=max(f[i-1][j]-pool[j],g[i-1][j+1]);

		rep(j,1,tot) f[i-1][j]=max(f[i-1][j],f[i-1][j-1]);

		f[i][p]=max(f[i][p],f[i-1][L[i]]+dat[i].l);
		f[i][p]=max(f[i][p],g[i-1][L[i]+1]+dat[i].p);

		int mx=p;
		repd(j,i-1,1)
		{
			mx=max(mx,R[j]);
			f[i][mx]=max(f[i][mx],f[j-1][L[i]]+pool[mx]-dat[i].p+dat[i].l);
			f[i][mx]=max(f[i][mx],g[j-1][L[i]+1]+pool[mx]);
		}
	}
	rep(i,0,tot) ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}