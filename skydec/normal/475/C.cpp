#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int n,m;
char str[1005][1005];int l[1005],r[1005];
int pl[1005],pr[1005];int S=0;
bool check(int sx,int sy,int lx,int ly)
{
	//printf("%d %d %d %d\n",sx,sy,lx,ly);
	rep(i,1,lx)if(!(l[sx+i-1]==sy&&r[sx+i-1]>=sy+ly-1))return 0;
	int nS=lx*ly;
	while(1)
	{
		int f1,f2;f1=f2=0;
		if(pl[sy+ly]<=sx+lx-1)
		{
			//if(lx==2&&ly==1)printf("_%d %d %d %d\n",sx,sy,pl[sy+ly],pr[sy+ly]);
			if(!(pl[sy+ly]==sx&&pr[sy+ly]>=sx+lx-1))f1=2;else if(f1!=2)f1=1;
		}
		if(l[sx+lx]<=sy+ly-1)
		{
			//if(lx==1&&ly==2)printf("_%d %d %d %d\n",sx,sy,l[sx+lx],r[sx+lx]);
			if(!(l[sx+lx]==sy&&r[sx+lx]>=sy+ly-1))
			{f2=2;}
			else if(f2!=2) f2=1;
		}
		//if(lx==2&&ly==1)printf("__%d %d %d %d\n",sx,sy,f1,f2);
		if(f1!=1&&f2!=1)break;
		if(f1==1&&f2==1)return 0;
		if(f1==1)
		{
			nS+=lx;sy++;
		}else {nS+=ly;sx++;}
	}
	//if(lx==2&&ly==1)printf("_____%d %d %d\n",sx,sy,nS);
	return nS==S;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%s",str[i]+1);
		rep(j,1,m)if(str[i][j]=='X'){l[i]=j;break;}
		per(j,m,1)if(str[i][j]=='X'){r[i]=j;break;}
		if(l[i])
		{
			rep(j,l[i],r[i])if(str[i][j]!='X')
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	rep(i,1,n)rep(j,1,m)if(str[i][j]=='X')S++;
	if(!S){printf("1\n");return 0;}
	rep(j,1,m)
	{
		rep(i,1,n)if(str[i][j]=='X'){pl[j]=i;break;}
		per(i,n,1)if(str[i][j]=='X'){pr[j]=i;break;}
		if(pl[j])
		{
			rep(i,pl[j],pr[j])if(str[i][j]!='X')
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	int Sp=-1;
	int x,y;bool fff=0;
	rep(i,1,n)rep(j,1,m)
	{
		if(fff)break;
		if(str[i][j]=='X'){x=i;y=j;fff=1;break;}
	}
	int dx=pr[y]-x+1;
	for(int i=1;i<=m;i++)if(check(x,y,dx,i)){Sp=dx*i;break;}
	
	int dy=r[x]-y+1;
	rep(i,1,n)if(check(x,y,i,dy))
	{
		int u=dy*i;
		if(Sp==-1||Sp>u)Sp=u;
	}
	printf("%d\n",Sp);
}