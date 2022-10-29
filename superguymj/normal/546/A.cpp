#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int k,w,n,ans;

int main()
{
	scanf("%d%d%d",&k,&n,&w);
	ans=k*(1+w)*w/2-n;
	printf("%d\n",max(0,ans));
	return 0;
}