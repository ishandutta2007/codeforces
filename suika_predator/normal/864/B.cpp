#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cctype>
using namespace std;
int n,m;
char str[233];
int flag[233];
int ans;
int main()
{
	scanf("%d %s",&n,str);
	int cur=0;
	for(int i=0;i<n;i++)
	{
		if(isupper(str[i]))
		{
			ans=max(ans,cur);
			memset(flag,0,sizeof(flag));
			cur=0;
		}
		else
		{
			if(!flag[str[i]-'a'])flag[str[i]-'a']=1,cur++;
		}
	}
	ans=max(ans,cur);
	printf("%d\n",ans);
	return 0;
}