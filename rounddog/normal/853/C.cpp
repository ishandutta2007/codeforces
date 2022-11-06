#include<cmath>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define maxn 2000020
#define inf 600020000

using namespace std;
typedef long long ll;

struct query{
	ll l,r,num,num2,f;
};

ll a[maxn],b[maxn],c[maxn],ans[maxn],sum[maxn],n,m,d[maxn],p,k,u,v,w,z,bl[maxn],nv;
ll h[maxn],nxt[maxn],to[maxn];
query q[maxn];

int lowbit(int x)
{
	return x&(-x);
}

void push_in(int x,int y)
{
	p++;
	to[p]=y;
	nxt[p]=h[x];
	h[x]=p;
}

void add(int x)
{
	int tmp=x;
	while (tmp<maxn)
	{
		b[tmp]++;
		tmp+=lowbit(tmp);
	}
}

int get_sum(int x)
{
	int tmp=x,tt=0;
	while (tmp)
	{
		tt+=b[tmp];
		tmp-=lowbit(tmp);
	}
	return tt;
}

void push_q(int u,int v,int w,int z,int nm)
{
	if (w>=u&&z>=v){
		nv++;
		bl[nv]=nm;
        k++;
		q[k].l=v-1;
		q[k].r=z;
		q[k].f=-1;
		q[k].num=nv;
		if (u>1) push_in(u-1,k);
		k++;
		q[k].l=v-1;
		q[k].r=z;
		q[k].f=1;
		q[k].num=nv;
		push_in(w,k);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	d[0]=0;
	for (int i=1;i<=n;i++) d[i]=d[i-1]+i-1;
	for (int i=1;i<=n;i++) ans[i]=0;
	k=0;p=0;nv=0;
	memset(h,0,sizeof(h));
	memset(nxt,0,sizeof(nxt));
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&u,&v,&w,&z);
		sum[i]=d[n];
		sum[i]-=d[u-1];
		sum[i]-=d[v-1];
		sum[i]-=d[n-w];
		sum[i]-=d[n-z];
		push_q(1,1,u-1,v-1,i);
		push_q(1,z+1,u-1,n,i);
		push_q(w+1,1,n,v-1,i);
		push_q(w+1,z+1,n,n,i);
	}
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++)
	{
		add(a[i]);
		for (int ii=h[i];ii;ii=nxt[ii])
		{
			int tc=to[ii];
			ans[q[tc].num]+=(get_sum(q[tc].r)-get_sum(q[tc].l))*q[tc].f;
		}
	}
	for (int i=1;i<=nv;i++)
	{
	    sum[bl[i]]+=d[ans[i]];
	}
	for (int i=1;i<=m;i++)
	    printf("%I64d\n",sum[i]);
    return 0;
}