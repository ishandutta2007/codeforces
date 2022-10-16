#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
char s[23333];
int ok[5555][5555];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=i;j<n;j++)
		{
			if(s[j]=='?'||s[j]=='(')
				cnt++;
			else
				cnt--;
			if(cnt>=0)
				ok[i][j]++;
			else
				break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		int cnt=0;
		for(int j=i;j>=0;j--)
		{
			if(s[j]=='?'||s[j]==')')
				cnt++;
			else
				cnt--;
			if(cnt>=0)
				ok[j][i]++;
			else
				break;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j+=2)
		{
			if(ok[i][j]==2)
			{
				//cout<<i<<' '<<j<<endl;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}