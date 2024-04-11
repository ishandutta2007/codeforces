#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020

using namespace std;

struct pot{
	int x,y,d[31];
};

pot a[maxn];
int dig[maxn][30],sum[maxn][30],n,ans[maxn],m,k,l;
bool f;

bool cmp(pot u,pot v)
{
	return (u.x<v.x);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&k);
		for (int j=0;j<30;j++)
		{
			a[i].d[j]=k%2;
			k=k/2;
		}
	}
	sort(a+1,a+m+1,cmp);
	memset(dig,0,sizeof(dig));
	for (int i=0;i<30;i++)
	{
		l=1;
		for (int j=1;j<=m;j++)
		    if (a[j].d[i]){
		    	for (int k=max(l,a[j].x);k<=a[j].y;k++) dig[k][i]=1;
		    	l=max(l,a[j].y);
		    }
		sum[0][i]=0;
		for (int j=1;j<=n;j++)
		    sum[j][i]=sum[j-1][i]+(1-dig[j][i]); 
		for (int j=1;j<=m;j++)
		    if (!a[j].d[i]&&sum[a[j].y][i]-sum[a[j].x-1][i]==0){
		    	printf("NO\n");
		    	return 0;
		    }
    }
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=n;i++)
        for (int j=0;j<30;j++)
            ans[i]+=dig[i][j]*(1<<j);
    printf("YES\n");
    for (int i=1;i<n;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}