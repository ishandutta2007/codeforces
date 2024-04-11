#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,m,a,b,x;
bool vis[2][10];

int main()
{
	scanf("%d%d",&n,&m),a=10,b=10;
	rep(i,1,n) scanf("%d",&x),a=min(a,x),vis[0][x]=1;
	rep(i,1,m) scanf("%d",&x),b=min(b,x),vis[1][x]=1;
	rep(i,1,9)
		if(vis[0][i] && vis[1][i])
		{
			printf("%d\n",i);
			return 0;
		}
	if(a>b) swap(a,b);
	printf("%d%d\n",a,b);
	return 0;
}