#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,m,k,ans;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) rep(j,2,m) rep(x,3,k) if(i+1==j && j+1==x) ans=max(ans,i+j+x);
	printf("%d\n",ans);
	return 0;
}