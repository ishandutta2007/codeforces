#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x1,x2,y1,y2,opt;
long long ans,key,S1[1005][1005],S2[1005][1005],S3[1005][1005],S4[1005][1005];

void Query(int x,int y)
{
	int xx=n-x,yy=n-y;
	if(xx&yy&1)
	for(i=x;i;i-=i&-i)
	for(j=y;j;j-=j&-j)
	ans^=S1[i][j];
	if(yy&1)
	for(i=x;i;i-=i&-i)
	for(j=y;j;j-=j&-j)
	ans^=S2[i][j];
	if(xx&1)
	for(i=x;i;i-=i&-i)
	for(j=y;j;j-=j&-j)
	ans^=S3[i][j];
	for(i=x;i;i-=i&-i)
	for(j=y;j;j-=j&-j)
	ans^=S4[i][j];
}

void Modify(int x,int y)
{
	int xx=n-x+1,yy=n-y+1;
	for(i=x;i<=n;i+=i&-i)
	for(j=y;j<=n;j+=j&-j)
	S1[i][j]^=key;
	if(xx&1)
	for(i=x;i<=n;i+=i&-i)
	for(j=y;j<=n;j+=j&-j)
	S2[i][j]^=key;
	if(yy&1)
	for(i=x;i<=n;i+=i&-i)
	for(j=y;j<=n;j+=j&-j)
	S3[i][j]^=key;
	if(xx&yy&1)
	for(i=x;i<=n;i+=i&-i)
	for(j=y;j<=n;j+=j&-j)
	S4[i][j]^=key;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ans=0;
			Query(x1-1,y1-1);
			Query(x1-1,y2);
			Query(x2,y1-1);
			Query(x2,y2);
			printf("%I64d\n",ans);
		}
		else
		{
			scanf("%d%d%d%d%I64d",&x1,&y1,&x2,&y2,&key);
			Modify(x1,y1);
			Modify(x1,y2+1);
			Modify(x2+1,y1);
			Modify(x2+1,y2+1);
		}
	}
}