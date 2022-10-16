#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int N=3005;
const int E=N<<1;
int n;
int h[N],nx[E],to[E],et;
bool vis[N];
int lk[E],cnt;
int l[E],r[E],L[E],R[E];
long long ans;
void ae(int u,int v)
{
	et++;
	to[et]=v;
	nx[et]=h[u];
	h[u]=et;
}
void extract(int u)
{
	vis[u]=1;
	lk[++cnt]=u;
	for (int i=h[u];i;i=nx[i])
		if (!vis[to[i]])
			extract(to[i]);
}
int q(int a,int b,int c)
{
	if (a>0&&b>0) return min(a,b);
	if (a==0&&b==0) return c;
	return a+b;
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			cnt=0;
			extract(i);
			lk[0]=lk[cnt];
			for (int j=1;j<=cnt;j++)
				lk[cnt+j]=lk[j];
			for (int j=1;j<=cnt;j++)
			{
				l[j-1]=n,r[j-1]=0;
				L[j-1]=2*n,R[j-1]=n;
				for (int k=j;k<j+cnt;k++)
				{
					l[k]=l[k-1],r[k]=r[k-1],L[k]=L[k-1],R[k]=R[k-1];
					if (lk[k]<=n)
						l[k]=min(l[k],lk[k]),r[k]=max(r[k],lk[k]);
					else
						L[k]=min(L[k],lk[k]),R[k]=max(R[k],lk[k]);
				}
				for (int k=j+1;k+1<j+cnt;k++)
				{
					if (l[k]!=l[k+1]||r[k]!=r[k+1]||L[k]!=L[k+1]||R[k]!=R[k+1])
					{
						int cl=l[k],cr=r[k],cL=L[k],cR=R[k];
						if (lk[j-1]<=n)
							cl=min(cl,lk[j-1]),cr=max(cr,lk[j-1]);
						else
							cL=min(cL,lk[j-1]),cR=max(cR,lk[j-1]);
						if (cl!=l[k]||cr!=r[k]||cL!=L[k]||cR!=R[k])
						{
							int vl=q(l[k]-cl,l[k]-l[k+1],l[k]),vr=q(cr-r[k],r[k+1]-r[k],n-r[k]+1);
							int vL=q(L[k]-cL,L[k]-L[k+1],L[k]-n),vR=q(cR-R[k],R[k+1]-R[k],2*n-R[k]+1);
							ans+=1ll*(k-j+1)/2*vl*vr*vL*vR;
						}
					}
				}
				if (j==1)
					ans+=1ll*cnt/2*(l[cnt])*(n-r[cnt]+1)
						*(L[cnt]-n)*(2*n-R[cnt]+1);
			}
		}
	printf("%lld\n",ans);
}
int main()
{
	solve();
	return 0;
}