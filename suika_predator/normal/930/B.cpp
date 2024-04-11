#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;
const long long MOD=1125899839733759ll;
int n,m,SHIFT;
char s[23333];
int cnt[33][5555][33],ok[33][5555],okk[33];
long long h[23333];
int main()
{
	srand(time(0)^(unsigned long long)(new char));
	SHIFT=rand()%2333+30;
	scanf(" %s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)s[n+i]=s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cnt[s[i]-'a'][j][s[i+j-1]-'a']++;
		}
	int ans=0;
	for(int i=0;i<26;i++)
	{
		int maxx=0;
		for(int j=1;j<=n;j++)
		{
			int c=0;
			for(int k=0;k<26;k++)
			{
				if(cnt[i][j][k]==1)
					c++;
			}
			if(c>maxx)maxx=c;
		}
		ans+=maxx;
	}
	printf("%.9lf\n",1.0*ans/n);
	return 0;
}