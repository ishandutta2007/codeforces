#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MXN 55
#define SI ({int x;scanf("%d",&x);x;})

const int inf = 100000000;
int G[MXN][MXN];
bool got[MXN][MXN];

int main()
{
	int n = SI, m = n*(n-1)/2-1;
	int a, b, x, y, i, j, k;
	
	while(m--)
	{
		x=SI; y=SI; G[x][y]=1;
		got[x][y]=got[y][x]=true;
	}
	
	for(i=1;i<=n;i++) for(j=1;j<i;j++)
		if(!got[i][j]){ x=i; y=j; break; }
	
	a=x; b=y;
	
	for(k=1;k<=n;k++)
	{
		if(k==x||k==y) continue;
		if(G[y][k]&&G[k][x]) a=y, b=x;
	}
	
	printf("%d %d\n",a,b);
	
	return 0;
}