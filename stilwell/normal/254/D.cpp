#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,d,i,j,k,tot,tmpx,tmpy;
int ratx[1005],raty[1005],id[1005][1005],dist[1005][1005];
int qx[1005],qy[1005],ll,rr;
char s[1005][1005];
bool rat[1005],rat2[1005];

void find_empty()
{
	int i,j;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]!='X')
	{
		printf("%d %d ",i,j);
		s[i][j]='X';
		return;
	}
}

void work4(int x,int y)
{
	dist[x][y]=1;
	qx[1]=x;qy[1]=y;ll=0;rr=1;
	while(ll<rr)
	{
		++ll;x=qx[ll];y=qy[ll];
		if(dist[x][y]==d)break;
		if(!dist[x-1][y]&&s[x-1][y]!='X')qx[++rr]=x-1,qy[rr]=y,dist[x-1][y]=dist[x][y]+1;
		if(!dist[x+1][y]&&s[x+1][y]!='X')qx[++rr]=x+1,qy[rr]=y,dist[x+1][y]=dist[x][y]+1;
		if(!dist[x][y-1]&&s[x][y-1]!='X')qx[++rr]=x,qy[rr]=y-1,dist[x][y-1]=dist[x][y]+1;
		if(!dist[x][y+1]&&s[x][y+1]!='X')qx[++rr]=x,qy[rr]=y+1,dist[x][y+1]=dist[x][y]+1;
	}
	for(ll=1;ll<=rr;++ll)dist[qx[ll]][qy[ll]]=0;
	for(ll=1;ll<=tot;++ll)rat2[ll]=false;
	for(ll=1;ll<=rr;++ll)if(id[qx[ll]][qy[ll]])rat2[id[qx[ll]][qy[ll]]]=true;
	for(ll=1;ll<=tot;++ll)if(!rat[ll]&&!rat2[ll])return;
	printf("%d %d %d %d ",tmpx,tmpy,qx[1],qy[1]);
	exit(0);
}

void work3(int x,int y)
{
	int qx[1005],qy[1005],ll,rr;
	dist[x][y]=1;
	qx[1]=x;qy[1]=y;ll=0;rr=1;
	while(ll<rr)
	{
		++ll;x=qx[ll];y=qy[ll];
		if(dist[x][y]==d)break;
		if(!dist[x-1][y]&&s[x-1][y]!='X')qx[++rr]=x-1,qy[rr]=y,dist[x-1][y]=dist[x][y]+1;
		if(!dist[x+1][y]&&s[x+1][y]!='X')qx[++rr]=x+1,qy[rr]=y,dist[x+1][y]=dist[x][y]+1;
		if(!dist[x][y-1]&&s[x][y-1]!='X')qx[++rr]=x,qy[rr]=y-1,dist[x][y-1]=dist[x][y]+1;
		if(!dist[x][y+1]&&s[x][y+1]!='X')qx[++rr]=x,qy[rr]=y+1,dist[x][y+1]=dist[x][y]+1;
	}
	for(ll=1;ll<=rr;++ll)dist[qx[ll]][qy[ll]]=0;
	for(ll=1;ll<=rr;++ll)work4(qx[ll],qy[ll]);
}

void work2(int x,int y)
{
	dist[x][y]=1;
	qx[1]=x;qy[1]=y;ll=0;rr=1;
	while(ll<rr)
	{
		++ll;x=qx[ll];y=qy[ll];
		if(dist[x][y]==d)break;
		if(!dist[x-1][y]&&s[x-1][y]!='X')qx[++rr]=x-1,qy[rr]=y,dist[x-1][y]=dist[x][y]+1;
		if(!dist[x+1][y]&&s[x+1][y]!='X')qx[++rr]=x+1,qy[rr]=y,dist[x+1][y]=dist[x][y]+1;
		if(!dist[x][y-1]&&s[x][y-1]!='X')qx[++rr]=x,qy[rr]=y-1,dist[x][y-1]=dist[x][y]+1;
		if(!dist[x][y+1]&&s[x][y+1]!='X')qx[++rr]=x,qy[rr]=y+1,dist[x][y+1]=dist[x][y]+1;
	}
	for(ll=1;ll<=rr;++ll)dist[qx[ll]][qy[ll]]=0;
	for(ll=1;ll<=tot;++ll)rat[ll]=false;
	for(ll=1;ll<=rr;++ll)if(id[qx[ll]][qy[ll]])rat[id[qx[ll]][qy[ll]]]=true;
	for(ll=1;ll<=tot;++ll)if(!rat[ll])break;
	if(ll>tot)
	{
		printf("%d %d ",qx[1],qy[1]);
		s[x][y]='X';
		find_empty();
		exit(0);
	}
	tmpx=qx[1];tmpy=qy[1];
	work3(ratx[ll],raty[ll]);
}

void work1(int x,int y)
{
	int qx[1005],qy[1005],ll,rr;
	dist[x][y]=1;
	qx[1]=x;qy[1]=y;ll=0;rr=1;
	while(ll<rr)
	{
		++ll;x=qx[ll];y=qy[ll];
		if(dist[x][y]==d)break;
		if(!dist[x-1][y]&&s[x-1][y]!='X')qx[++rr]=x-1,qy[rr]=y,dist[x-1][y]=dist[x][y]+1;
		if(!dist[x+1][y]&&s[x+1][y]!='X')qx[++rr]=x+1,qy[rr]=y,dist[x+1][y]=dist[x][y]+1;
		if(!dist[x][y-1]&&s[x][y-1]!='X')qx[++rr]=x,qy[rr]=y-1,dist[x][y-1]=dist[x][y]+1;
		if(!dist[x][y+1]&&s[x][y+1]!='X')qx[++rr]=x,qy[rr]=y+1,dist[x][y+1]=dist[x][y]+1;
	}
	for(ll=1;ll<=rr;++ll)dist[qx[ll]][qy[ll]]=0;
	for(ll=1;ll<=rr;++ll)work2(qx[ll],qy[ll]);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&d);++d;
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='R')
	{
		id[i][j]=++tot;
		if(tot>1000){printf("-1\n");return 0;}
		ratx[tot]=i;raty[tot]=j;
	}
	if(tot==0)
	{
		find_empty();
		find_empty();
		return 0;
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	if(s[i][j]=='R')
	{
		work1(i,j);
		printf("-1\n");
		return 0;
	}
}