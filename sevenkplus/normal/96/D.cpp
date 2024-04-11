#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1010
#define INF 1000000000000000000LL
int n,m,L,R,t[N],c[N],q[N];vector<int> a[N],w[N];
ll d[N];int he[N],ad[N*N],ne[N*N],di[N*N],_;bool v[N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&L,&R);
	for(int i=1,x,y,z;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),
		a[x].push_back(y),w[x].push_back(z),
		a[y].push_back(x),w[y].push_back(z);
	for(int i=1,x,y,z;i<=n;i++)
		scanf("%d%d",t+i,c+i);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)d[j]=INF,v[j]=0;
		int l=0,r=0,C=1;q[0]=i,v[i]=1;d[i]=0;
		while(C)
		{
			int x=q[l];C--;v[x]=0;
			for(int i=0;i<(int)a[x].size();i++)
			{
				if(d[x]+w[x][i]<d[a[x][i]])
				{
					d[a[x][i]]=d[x]+w[x][i];
					if(!v[a[x][i]]){r++;C++;if(r==N)r=0;v[q[r]=a[x][i]]=1;}
				}
			}
			l++;if(l==N)l=0;
		}
		for(int j=1;j<=n;j++)if(i!=j&&d[j]<=t[i])_++,ne[_]=he[i],he[i]=_,ad[_]=j,di[_]=c[i];
	}
	for(int i=1;i<=n;i++)d[i]=INF,v[i]=0;
	int l=0,r=0,C=1;q[0]=L;v[L]=1;d[L]=0;
	while(C)
	{
		int x=q[l];C--;v[x]=0;
		for(int p=he[x];p;p=ne[p])
			if(d[x]+di[p]<d[ad[p]])
			{
				d[ad[p]]=d[x]+di[p];
				if(!v[ad[p]]){C++;r++;if(r==N)r=0;v[q[r]=ad[p]]=1;}
			}
		l++;if(l==N)l=0;
	}
	if(d[R]==INF)puts("-1");else printf("%I64d\n",d[R]);
	return 0;
}