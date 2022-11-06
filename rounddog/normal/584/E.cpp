#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 2000020

using namespace std;

int n,m,a[maxn],b[maxn],p1[maxn],p2[maxn],x[maxn],y[maxn],ans,sum,k,t;
bool v[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p1[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		p2[b[i]]=i;
	}
	ans=sum=0;
	for (int i=1;i<=n;i++)
	{
		k=p1[b[i]];
		sum+=k-i;
		if (k!=i) do{
			t=i;
			while (p2[a[t]]<k) t++;
			p1[a[t]]=k;
			p1[a[k]]=t;
			swap(a[k],a[t]);
			ans++;
			x[ans]=k,y[ans]=t;
			k=t;
		}while (t!=i);
	}
	printf("%d\n",sum);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
	    printf("%d %d\n",x[i],y[i]);
	return 0;
}