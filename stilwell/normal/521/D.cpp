#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int K,n,m,i,j,k,opt,u,v,tot;
int a[100005],b[100005],c[100005];
int d[100005],e[100005],h[100005];
long long now;

vector<int> V[100005],V0[100005];

struct node
{
	long long A,B;
	int id;
}t[100005];
inline bool cmp(const node &a,const node &b){return (long double)a.A/a.B>(long double)b.A/b.B;}
inline bool cmp2(const int &a,const int &b){return d[a]>d[b];}
inline bool cmp3(const node &a,const node &b){return h[a.id]<h[b.id];}

int main()
{
	scanf("%d%d%d",&K,&n,&m);
	for(i=1;i<=K;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",&opt,&u,&v);
		h[i]=opt;
		if(opt==1)
		{
			if(v>b[u])b[u]=v,c[u]=i;
		}
		if(opt==2)
		{
			V[u].push_back(v);
			V0[u].push_back(i);
		}
		if(opt==3)
		{
			++tot;
			t[tot].A=v;
			t[tot].B=1;
			t[tot].id=i;
		}
	}
	for(i=1;i<=K;++i)
	if(b[i]>a[i])
	{
		V[i].push_back(b[i]-a[i]);
		V0[i].push_back(c[i]);
	}
	for(i=1;i<=K;++i)
	{
		k=V[i].size();
		if(k==0)continue;
		for(j=0;j<k;++j)
		{
			d[j]=V[i][j];
			e[j]=j;
		}
		sort(e,e+k,cmp2);
		now=a[i];
		for(j=0;j<k;++j)
		{
			++tot;
			t[tot].A=now+d[e[j]];
			t[tot].B=now;
			now+=d[e[j]];
			t[tot].id=V0[i][e[j]];
		}
	}
	sort(t+1,t+tot+1,cmp);
	if(m>tot)m=tot;
	sort(t+1,t+m+1,cmp3);
	printf("%d\n",m);
	for(i=1;i<=m;++i)printf("%d ",t[i].id);
}