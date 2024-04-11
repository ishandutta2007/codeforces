#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 100000
#define INF 1000000000
using namespace std;
int x,y,n,ans;
char s[MAXN];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	x=0;
	y=0;
	ans=INF;
	for(int i=0;i<strlen(s);i++)
	{
		if(i%2==0&&s[i]=='b') y++;
		if(i%2==1&&s[i]=='r') x++;
	}
	ans=min(ans,max(x,y));
	x=0;
	y=0;
		for(int i=0;i<strlen(s);i++)
	{
		if(i%2==1&&s[i]=='b') y++;
		if(i%2==0&&s[i]=='r') x++;
	}
	ans=min(ans,max(x,y));
	printf("%d",ans);
	return 0;
}