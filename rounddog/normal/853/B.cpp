#include<cmath>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define maxn 2000050
#define inf 1000000007

using namespace std;
typedef long long ll;

struct point{
	ll date,city,cost;
};

bool cmp(point x,point y)
{
	return (x.city<y.city||x.city==y.city&&x.date>y.date);
}

point a[maxn],b[maxn];
ll n,m,k,c1,c2,j,mc[maxn],md[maxn],p,lf,rt,cnt,sum1,sum2,ans;
ll nxt1[maxn],nxt2[maxn],h1[maxn],h2[maxn],e1[maxn],e2[maxn],to1[maxn],to2[maxn];
bool f;

void push1(int x)
{
	p++;
	to1[p]=a[x].city;
	e1[p]=a[x].cost;
	nxt1[p]=h1[a[x].date];
	h1[a[x].date]=p;
}

void push2(int x)
{
	p++;
	to2[p]=b[x].city;
	e2[p]=mc[b[x].city];
	nxt2[p]=h2[b[x].date];
	h2[b[x].date]=p;
}

void check1(int x)
{
	for (int ii=h1[x];ii;ii=nxt1[ii])
	{
		int tmp=to1[ii];
		if (md[tmp]==inf){
			cnt--;
			sum1+=e1[ii];
			md[tmp]=e1[ii];
		}
		else if (e1[ii]<md[tmp]){
			sum1+=e1[ii]-md[tmp];
			md[tmp]=e1[ii];
		}
	}
}

void check2(int x)
{
	for (int ii=h2[x];ii;ii=nxt2[ii])
	{
		int tmp=to2[ii];
		sum2+=e2[ii]-mc[tmp];
		mc[tmp]=e2[ii];
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);c1=c2=0;p=0;
	memset(nxt1,0,sizeof(nxt1));
	memset(nxt2,0,sizeof(nxt2));
	memset(h1,0,sizeof(h1));
	memset(h2,0,sizeof(h2));
	for (int i=0;i<m;i++)
	{
		int u,v,w,z;
		scanf("%d%d%d%d",&u,&v,&w,&z);
		if (w==0){
			c1++;
			a[c1].date=u;
			a[c1].city=v;
			a[c1].cost=z;
		}
		else{
			c2++;
			b[c2].date=u;
			b[c2].city=w;
			b[c2].cost=z;
		}
	}
	for (int i=1;i<=c1;i++)
	    push1(i);
    p=0;
	sort(b+1,b+c2+1,cmp);
	j=1;f=true;lf=1;rt=maxn-1;
	for (int i=1;i<=n;i++)
	{
		mc[i]=inf;
		if (b[j].city!=i) f=false;
		else rt=min(rt,b[j].date);
	    while (j<=c2&&b[j].city==i){
	    	push2(j);
	    	mc[i]=min(mc[i],b[j].cost);
	    	j++;
	    }
	}
	if (!f) {printf("-1\n");return 0;}
	rt-=k;sum2=sum1=0;
	for (int i=1;i<=n;i++)
	{
		md[i]=inf;
		sum2+=mc[i];
	}
	lf=1;cnt=n;ans=(ll)inf*inf;
	for (int i=1;i<=k;i++) check2(i);
	while (lf<rt)
	{
		check1(lf);check2(lf+k);
		if (!cnt) ans=min(ans,sum2+sum1);
		lf++;
	}
	if (cnt) printf("-1\n"); else printf("%I64d\n",ans);
	return 0;
}