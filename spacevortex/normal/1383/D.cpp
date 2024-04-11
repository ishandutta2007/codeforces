#include<bits/stdc++.h>
#define pii pair<int,int>
#define crp make_pair
#define fi first
#define se second
#define cmax(a,b) a=max(a,b)
using namespace std;
const int N=260;
int n,m,X,Y;
int a[N][N],t[N][N],hmx[N*N],lmx[N*N];
queue<pii> que;
int main()
{
	int i,j,w,num;
	pii now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		w=0;
		for(j=1;j<=m;j++) cmax(w,a[i][j]);
		hmx[w]=1;
	}
	for(j=1;j<=m;j++)
	{
		w=0;
		for(i=1;i<=n;i++) cmax(w,a[i][j]);
		lmx[w]=1;
	}
	X=Y=0;
	for(num=n*m;num>=1;num--)
	{
		if(hmx[num]==0&&lmx[num]==0)
		{
			now=que.front();que.pop();
			t[now.fi][now.se]=num;
			continue;
		}
		if(hmx[num]) X++;
		if(lmx[num]) Y++;
		t[X][Y]=num;
		if(hmx[num]) for(i=Y-1;i>=1;i--) que.push(crp(X,i));
		if(lmx[num]) for(i=X-1;i>=1;i--) que.push(crp(i,Y));
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) printf("%d ",t[i][j]);
		putchar('\n');
	}
	return 0;
}