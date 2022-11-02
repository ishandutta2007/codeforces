#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;

int n,i,j,k,x,y;
long long ans;

map <int,int> X,Y;
map < pair<int,int> ,int> XY;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		ans+=X[x];ans+=Y[y];
		ans-=XY[make_pair(x,y)];
		++X[x];++Y[y];++XY[make_pair(x,y)];
	}
	printf("%I64d\n",ans);
}