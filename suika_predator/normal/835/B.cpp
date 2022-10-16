#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,sum,ans;
char s[100010];
int cnt[15];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		cnt[s[i]-'0']++;
		sum+=s[i]-'0';
	}
	while(sum<n)
	{
		for(int i=0;i<=9;i++)
		{
			if(cnt[i])
			{
				sum-=i;
				sum+=9;
				cnt[i]--;
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}