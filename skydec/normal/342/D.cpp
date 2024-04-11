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
#define jsb 1000000007
using namespace std;
int n;
char str[5][11000];
bool mp[5][11000];
int f[11000][8][2];int pang[11000];
int cx,cy;
inline void A(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
inline bool put(int x1,int y1,int x2,int y2)
{
	if(x1>3||x2>3||y1>n||y2>n)return 0;
	if(x1==x2)
	{
		if(y2<y1)swap(y1,y2);
		if(y1-1==cy||y2+1==cy)return 1;else return 0;
	}
	if(y1==y2)
	{
		if(cx==2)return 0;
		if(y1!=cy)return 0;
		if(x1+x2==7-cx)return 1;else return 0;
	}
}
int dfs(int now,int zt,int flag)
{
	//printf("_%d %d %d\n",now,zt,flag);
	#define orz f[now][zt][flag]
	if(now==n+1)return (!zt)&&flag;
	if(orz!=-1)return orz;
	orz=0;
	//321
	//OOX
	if(zt==1)
	{
		A(orz,dfs(now+1,pang[now+1],flag|put(2,now,3,now)));
		if(!(6&pang[now+1]))A(orz,dfs(now+1,pang[now+1]|6,flag|put(2,now,2,now+1)|put(3,now,3,now+1)));
		}
	//XOX
	if(zt==5)
	{
		if(!(2&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|2,flag|put(2,now,2,now+1)));
	}
	//XXX
	if(zt==7)return orz=dfs(now+1,pang[now+1],flag);
	//XOO
	if(zt==4)
	{
		A(orz,dfs(now+1,pang[now+1],flag|put(2,now,1,now)));
		if(!(3&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|3,flag|put(2,now,2,now+1)|put(1,now,1,now+1)));
	}
	//OXX
	if(zt==3)
	{
		if(!(4&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|4,flag|put(3,now,3,now+1)));
	}
	//XXO
	if(zt==6)
	{
		if(!(1&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|1,flag|put(1,now,1,now+1)));
	}
	//OOO
	if(zt==0)
	{
		if(!(7&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|7,flag|put(1,now,1,now+1)|put(2,now,2,now+1)|put(3,now,3,now+1)));
		if(!(1&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|1,flag|put(2,now,2,now+1)|put(3,now,3,now+1)));
		if(!(4&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|4,flag|put(1,now,1,now+1)|put(2,now,2,now+1)));
	}
	//OXO
	if(zt==2)
	{
		if(!(5&pang[now+1]))
		A(orz,dfs(now+1,pang[now+1]|5,flag|put(1,now,1,now+1)|put(3,now,3,now+1)));
	}
	return orz;	
}
#undef orz
void DEBUG()
{
	//--------just for debug
	printf("__%d\n",dfs(3,2,1));
}
int main()
{
	scanf("%d",&n);rep(i,1,3)scanf("%s",str[i]+1);int ans=0;
	rep(i,1,3)rep(j,1,n)if(str[i][j]=='O'){mp[i][j]=0;cx=i;cy=j;}else mp[i][j]=(str[i][j]=='.');
	memset(f,-1,sizeof f);rep(i,1,n)rep(j,1,3)pang[i]+=(1<<(j-1))*(!mp[j][i]);
	//DEBUG();
	printf("%d\n",dfs(1,pang[1],0));return 0;
}