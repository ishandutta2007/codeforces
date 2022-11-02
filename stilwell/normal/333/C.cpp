#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,T,i,j,k;
int use[100005];

int Abs(int x){if(x<0)return -x;return x;}

void dfs(int x,int y,int z,int now,int last)
{
	if(now!=-1)
	{
		if(last!=-1)
		{
			dfs(x,y,z+last,-1,now);
			dfs(x,y,z-last,-1,now);
			dfs(x,y,z,-1,last*now);
			dfs(x,y,z,-1,last+now);
			dfs(x,y,z,-1,last-now);
		}else dfs(x,y,z,-1,now);
	}
	if(x>4)
	{
		if(now!=-1)return;
		if(last!=-1)
		{
			dfs(x,y,z+last,-1,-1);
			dfs(x,y,z-last,-1,-1);
			return;
		}
		if(use[Abs(n-z)]!=T&&Abs(n-z)<10000)
		{
			if(!m)exit(0);--m;
			use[Abs(n-z)]=T;
			printf("%04d%04d\n",T,Abs(n-z));
		}
		return;
	}
	if(now==-1)now=0;
	now=now*10+y%10;
	dfs(x+1,y/10,z,now,last);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(T=0;T<=9999;++T)
	{
		k=(T%100%10*10+T%100/10)*100+(T/100%10*10+T/1000);
		dfs(1,k,0,-1,-1);
	}
}