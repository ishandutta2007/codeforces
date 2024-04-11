#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> VC;
const int N=1050;
int n,tot=0,m=0;
int siz[N],p[N],h[N],ex[N],ey[N];
VC RT,U;
namespace GRD
{
	int f[N][N];
	void init()
	{
		int i,j,k,u,v;
		memset(f,0x3f,sizeof(f));
		for(i=1;i<=n;i++) f[i][i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			f[u][v]=f[v][u]=1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
	}
	int qry(VC A,VC B,int x)
	{
		int i,j,a,b,asi,bsi,ans=0;
		asi=A.size();bsi=B.size();
		for(i=0;i<asi;i++)
		{
			for(j=0;j<bsi;j++)
			{
				a=A[i];b=B[j];
				if(f[a][x]+f[x][b]==f[a][b]) ans++;
			}
		}
		return ans;
	}
}
int qry(VC S,VC T,int v)
{
	/*
	puts("qry");
	for(int w:S) printf("%d ",w);putchar('\n');
	for(int w:T) printf("%d ",w);putchar('\n');
	printf("%d\n\n",v);
	return GRD::qry(S,T,v); 
	*/
	int tot,i,ret;
	tot=S.size();
	printf("%d\n",tot);
	for(i=0;i<tot;i++) printf("%d ",S[i]);putchar('\n');
	tot=T.size();
	printf("%d\n",tot);
	for(i=0;i<tot;i++) printf("%d ",T[i]);putchar('\n');
	printf("%d\n",v);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
bool cmp(const int &a,const int &b)
{
	return siz[a]>siz[b];
}
VC get(int len)
{
	int i;
	VC s;
	s.clear();	
	for(i=1;i<=len;i++) s.pb(h[i]);
	return s;
}
int main()
{
	//freopen("a.in","r",stdin);
	int i,j,sl,sr,mid;
	scanf("%d",&n);
	//GRD::init();
	RT.clear();RT.pb(1);
	U.clear();
	for(i=2;i<=n;i++) U.pb(i); 
	siz[1]=n;
	for(i=2;i<=n;i++) siz[i]=qry(RT,U,i);
	for(i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=n;i>=1;i--)
	{
		while(true) 
		{
			if(tot==0||qry(RT,get(tot),p[i])==0) break;
			sl=1;sr=tot;
			while(sl<sr)
			{
				mid=(sl+sr)>>1;
				if(qry(RT,get(mid),p[i])>0) sr=mid;
				else sl=mid+1;
			}
			m++;ex[m]=p[i];ey[m]=h[sl];
			for(j=sl;j<tot;j++) h[j]=h[j+1];
			tot--;
		}
		for(j=tot+1;j>1;j--) h[j]=h[j-1];
		h[1]=p[i];tot++;
	}
	puts("ANSWER");
	for(i=1;i<n;i++) printf("%d %d\n",ex[i],ey[i]);
	fflush(stdout);
	return 0;
}