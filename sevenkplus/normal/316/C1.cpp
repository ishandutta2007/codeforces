#include<cstdio>
#include<algorithm>
using namespace std;
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 83
#define N2 6410
#define M2 6410*10
int he[N2],ne[M2],ad[M2],di[M2],wi[M2];
void addE(int x,int y,int z,int w)
{
    static int t=1;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y,di[t]=z,wi[t]=w,
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x,di[t]=0,wi[t]=-w;
}
#define INF 1000000007
int q[N2*100],pr[N2],ed[N2],d[N2];bool v[N2];
bool spfa(int s,int t,int c)
{
    memset(v,0,sizeof v);
    for(int i=0;i<c;i++)d[i]=INF;
    int l=1,r=1;q[1]=s,v[s]=1,d[s]=0;
    while(l<=r)
    {
        int x=q[l++];v[x]=0;
        for(int p=he[x];p;p=ne[p])if(di[p])
            if(d[x]+wi[p]<d[ad[p]])
            {
                d[ad[p]]=d[x]+wi[p],pr[ad[p]]=x,ed[ad[p]]=p;
                if(!v[ad[p]])v[ad[p]]=1,q[++r]=ad[p];
            }
    }
    return d[t]<INF;
}
int ff(int s,int t,int c)
{
    int S=0;
    while(spfa(s,t,c))
    {
        int nf=INF;
        for(int i=t;i!=s;i=pr[i])nf=min(nf,di[ed[i]]);
        S+=nf*d[t];
        for(int i=t;i!=s;i=pr[i])di[ed[i]]-=nf,di[ed[i]^1]+=nf;
    }
    return S;
}
const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int n,m,a[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",a[i]+j);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)if((i+j)&1)
			for(int d=0;d<4;d++)
			{
				int x=i+dx[d],y=j+dy[d];
				if(x<0||x>=n||y<0||y>=m)continue;
				addE(i*m+j,x*m+y,1,a[i][j]!=a[x][y]);
			}
	int le=n*m,ri=n*m+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if((i+j)&1)addE(le,i*m+j,1,0);
			else addE(i*m+j,ri,1,0);
	printf("%d\n",ff(le,ri,ri+1));
	return 0;
}