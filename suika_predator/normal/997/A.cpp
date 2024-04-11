#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,x,y;
char s[333333];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	s[n+1]='1';
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'&&s[i+1]=='1')
			cnt++;
	}
	if(cnt==0)return printf("0\n"),0;
	printf("%lld\n",y+(1ll*min(x,y))*(cnt-1));
	return 0;
}