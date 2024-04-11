#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int n,i,j,k;
long long a[100005],b[100005],sum,m,l,r,mid,Min,Max,lim,ans,aim;

struct node
{
	int l,r,sum;
}t[10000005];
int root[100005],tot;

void C(int &p,long long l,long long r)
{
	t[++tot]=t[p];
	p=tot;
	++t[p].sum;
	if(l==r)return;
	long long mid=l+r>>1;
	if(aim<=mid)C(t[p].l,l,mid);
	else C(t[p].r,mid+1,r);
}

void Q(int p,long long l,long long r)
{
	if(!p)return;
	if(aim>=r)
	{
		sum+=t[p].sum;
		return;
	}
	long long mid=l+r>>1;
	Q(t[p].l,l,mid);
	if(aim>mid)Q(t[p].r,mid+1,r);
}

int Time;

int main()
{
	//Time=clock();
	//freopen("1.txt","r",stdin);
	scanf("%d%I64d",&n,&m);
	Min=0;Max=0;
	for(i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
		if(a[i]<0)Min-=a[i];
		if(a[i]>0)Max+=a[i];
		a[i]+=a[i-1];
		//if(a[i]<Min)Min=a[i];
		//if(a[i]>Max)Max=a[i];
	}
	for(i=n;i>=1;--i)b[i]=b[i+1]+i;
	
	Min+=1000;Max+=1000;
	lim=Min+Max;
	
	aim=Min;C(root[1],1,lim);
	for(i=1;i<n;++i)
	{
		aim=a[i]+Min;
		root[i+1]=root[i];
		C(root[i+1],1,lim);
	}
	l=-Min;r=Max;ans=-Min;
	while(l<=r)
	{
		mid=(l+r)/2;
		sum=0;
		for(i=1;i<=n;++i)
		{
			aim=a[i]+Min-mid;
			if(aim>=1)Q(root[i],1,lim);
			//if(sum>=m||sum+b[i+1]<m)break;
		}
		if(sum>=m)l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%I64d\n",ans);
	//printf("%d\n",clock()-Time);
	//for(;;);
}