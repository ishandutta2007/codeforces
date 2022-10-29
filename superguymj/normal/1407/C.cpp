#include<algorithm>
#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
int n,ans[10005];

int main()
{
	scanf("%d",&n);
	int x=1;
	int a,b;
	rep(i,2,n)
	{
		printf("? %d %d\n",x,i);
		fflush(stdout);
		scanf("%d",&a);
		printf("? %d %d\n",i,x);
		fflush(stdout);
		scanf("%d",&b);
		if(a>b) ans[x]=a,x=i;
		else ans[i]=b;
	}
	ans[x]=n;
	printf("! ");
	rep(i,1,n) printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
	return 0;
}