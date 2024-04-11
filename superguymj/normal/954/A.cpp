#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,ans;
char s[200];

int main()
{
	scanf("%d%s",&n,s+1),ans=n;
	for(int i=1; i<n; ++i)
		if(s[i]!=s[i+1]) --ans,++i;
	printf("%d\n",ans);
	return 0;
}