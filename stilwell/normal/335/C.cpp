#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,ans,top,T;
int Mex[105][100005],sg[105][105][20];

struct node
{
	int x,y;
}t[105];
inline bool cmp(const node &a,const node &b){return a.x<b.x;}

int Sg(int l,int r,int ban)
{
	if(l>r)return 0;
	if(sg[l][r][ban])return sg[l][r][ban]-1;
	int i,j,t=++T;
	++top;
	for(i=l;i<=r;++i)
	for(j=1;j<=2;++j)
	{
		if(i==l&&j==1&&(ban&2))continue;
		if(i==l&&j==2&&(ban&1))continue;
		if(i==r&&j==1&&(ban&8))continue;
		if(i==r&&j==2&&(ban&4))continue;
		if(j==1)Mex[top][Sg(l,i-1,(ban&(1+2))+4)^Sg(i+1,r,(ban&(4+8))+1)]=t;
		else Mex[top][Sg(l,i-1,(ban&(1+2))+8)^Sg(i+1,r,(ban&(4+8))+2)]=t;
	}
	for(i=0;;++i)if(Mex[top][i]!=t)break;
	sg[l][r][ban]=i+1;
	--top;
	return i;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&t[i].x,&t[i].y);
	if(m==0)ans=Sg(1,n,0);
	else
	{
		sort(t+1,t+m+1,cmp);
		if(t[1].y==1)ans^=Sg(1,t[1].x-1,4);
		else ans^=Sg(1,t[1].x-1,8);
		if(t[m].y==1)ans^=Sg(t[m].x+1,n,1);
		else ans^=Sg(t[m].x+1,n,2);
		for(i=2;i<=m;++i)
		{
			j=0;
			if(t[i-1].y==1)j+=1;else j+=2;
			if(t[i].y==1)j+=4;else j+=8;
			ans^=Sg(t[i-1].x+1,t[i].x-1,j);
		}
	}
	if(ans)printf("WIN\n");
	else printf("LOSE\n");
}