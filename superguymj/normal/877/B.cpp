#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
char s[5005];
int c[5005][2],ans,n;

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n)
		c[i][0]=c[i-1][0],c[i][1]=c[i-1][1],++c[i][s[i]-'a'];
	rep(i,0,n)
		rep(j,i+1,n+1)
			ans=max(ans,c[i][0]+c[j-1][1]-c[i][1]+c[n][0]-c[j-1][0]);
	printf("%d\n",ans);
	return 0;
}