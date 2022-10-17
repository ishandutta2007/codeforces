#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define PB push_back
#define N 4005
vector< int > e[N];
int n,m,d,r,w[N],p[N],q[N],v[N],x[N],y[N],nxt[N],son[N],f[N],pre[N];
bool cmp(const int i,const int j){return w[i]<w[j];}
bool cmpL(const int i,const int j){return 0LL+y[i]-x[i]<0LL+y[j]-x[j];}
void work(int k,int L,int R)
{
	for (int i=L;i<=R;i++) f[i]=0,pre[i]=0;
	for (int i=L;i<R;i++){
		if (f[i]>f[i+1]) f[i+1]=f[i],pre[i+1]=pre[i];
		for (int p=son[i];p;p=nxt[p]) if (p!=k)
			if (f[i]+v[p]>f[y[p]]) f[y[p]]=f[i]+v[p],pre[y[p]]=p;
		}
	for (int p=R;pre[p];p=x[p]) p=pre[p],e[k].PB(p); v[k]+=f[R];
}
int main()
{
	scanf("%d",&n); w[m++]=-int(2e9)-7,w[m++]=int(2e9)+7;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&d,&r),w[m++]=d-r,w[m++]=d+r,v[i]=1,q[i]=i;
	for (int i=0;i<m;i++) p[i]=i; sort(p,p+m,cmp),m=0;
	for (int k=0;k<n+n+2;k++){
		int i=p[k]; if (!k || w[i]!=w[p[k-1]]) m++;
		if (i&1) y[i/2]=m; else x[i/2]=m;
		}
	for (int i=0;i<=n;i++) nxt[i]=son[x[i]],son[x[i]]=i; sort(q,q+n+1,cmpL);
	for (int i=0;i<=n;i++) work(q[i],x[q[i]],y[q[i]]);
	printf("%d\n",v[0]); int h=0,t=1; f[1]=0;
	while (h<t){
		int i=f[++h],L=e[i].size();
		for (int j=0;j<L;j++) f[++t]=e[i][j];
		}
	for (int i=2;i<=t;i++) printf("%d%s",f[i],i<t?" ":"\n");
	return 0;
}