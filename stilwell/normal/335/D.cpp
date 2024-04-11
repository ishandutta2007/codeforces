#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,X,Y,tot;
int ansx,ansy,ansd,d;
int x1[100005],x2[100005],y1[100005],y2[100005];
int x[400005],y[400005],l[400005],lnum[400005],u[400005],unum[400005];
int sum[3005][3005],esum[4][3005][3005];
bool dot[3005][3005];

struct node
{
	int x,y,id;
}t[400005];
inline bool cmpx(const node &a,const node &b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
inline bool cmpy(const node &a,const node &b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}

inline bool Edge(int x1,int x2,int y1,int y2,int z)
{
	--x1;--y1;
	return esum[z][x2][y2]-esum[z][x1][y2]-esum[z][x2][y1]+esum[z][x1][y1]==(x2-x1)*(y2-y1);
}

inline bool S(int x1,int x2,int y1,int y2)
{
	--x1;--y1;
	return sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1]==(x2-x1)*(y2-y1);
}

void check(int i,int d)
{
	if(Edge(x[i]-d,x[i]-d,y[i]-d,y[i],2)&&Edge(x[i]-d,x[i],y[i]-d,y[i]-d,0))
	ansd=d,ansx=x[i],ansy=y[i];
}

int main()
{
	scanf("%d",&n);
	ansd=-1;
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		++x1[i];++y1[i];
		if(x2[i]-x1[i]==y2[i]-y1[i]&&x2[i]-x1[i]>ansd)
		ansd=x2[i]-x1[i],ansx=x2[i],ansy=y2[i];
		if(x2[i]>X)X=x2[i];if(y2[i]>Y)Y=y2[i];
		dot[x1[i]][y1[i]]=true;dot[x1[i]][y2[i]]=true;
		dot[x2[i]][y1[i]]=true;dot[x2[i]][y2[i]]=true;
		for(j=x1[i];j<=x2[i];++j)
		for(k=y1[i];k<=y2[i];++k)
		sum[j][k]=1;
		for(j=x1[i];j<=x2[i];++j)esum[0][j][y1[i]]=esum[1][j][y2[i]]=1;
		for(j=y1[i];j<=y2[i];++j)esum[2][x1[i]][j]=esum[3][x2[i]][j]=1;
	}
	for(i=1;i<=X;++i)
	{
		for(j=1;j<=Y;++j)sum[i][j]+=sum[i][j-1],esum[0][i][j]+=esum[0][i][j-1],esum[1][i][j]+=esum[1][i][j-1],esum[2][i][j]+=esum[2][i][j-1],esum[3][i][j]+=esum[3][i][j-1];
		for(j=1;j<=Y;++j)sum[i][j]+=sum[i-1][j],esum[0][i][j]+=esum[0][i-1][j],esum[1][i][j]+=esum[1][i-1][j],esum[2][i][j]+=esum[2][i-1][j],esum[3][i][j]+=esum[3][i-1][j];
	}
	for(i=1;i<=X;++i)
	for(j=1;j<=Y;++j)
	if(dot[i][j])x[++tot]=i,y[tot]=j;
	for(i=1;i<=tot;++i)t[i].x=x[i],t[i].y=y[i],t[i].id=i;
	sort(t+1,t+tot+1,cmpx);
	for(i=2;i<=tot;++i)if(t[i].x==t[i-1].x)l[t[i].id]=t[i-1].id,lnum[t[i].id]=lnum[l[i]]+1;
	sort(t+1,t+tot+1,cmpy);
	for(i=2;i<=tot;++i)if(t[i].y==t[i-1].y)u[t[i].id]=t[i-1].id,unum[t[i].id]=unum[u[i]]+1;
	for(i=1;i<=tot;++i)
	if(lnum[i]<unum[i])
	{
		for(j=l[i];j;j=l[j])
		{
			d=y[i]-y[j];
			if(!Edge(x[i]-d,x[i],y[i],y[i],1))break;
			if(!Edge(x[i],x[i],y[i]-d,y[i],3))break;
			if(!S(x[i]-d,x[i],y[i]-d,y[i]))break;
			if(d<=ansd)continue;
			check(i,d);
		}
	}
	else
	{
		for(j=u[i];j;j=u[j])
		{
			d=x[i]-x[j];
			if(!Edge(x[i]-d,x[i],y[i],y[i],1))break;
			if(!Edge(x[i],x[i],y[i]-d,y[i],3))break;
			if(!S(x[i]-d,x[i],y[i]-d,y[i]))break;
			if(d<=ansd)continue;
			check(i,d);
		}
	}
	if(ansd==-1)printf("NO\n");
	else
	{
		k=0;
		for(i=1;i<=n;++i)
		if(x1[i]>=ansx-ansd&&x2[i]<=ansx&&y1[i]>=ansy-ansd&&y2[i]<=ansy)
		++k;
		printf("YES %d\n",k);
		for(i=1;i<=n;++i)
		if(x1[i]>=ansx-ansd&&x2[i]<=ansx&&y1[i]>=ansy-ansd&&y2[i]<=ansy)
		{
			printf("%d",i);
			--k;if(k==0)printf("\n");else printf(" ");
		}
	}
}