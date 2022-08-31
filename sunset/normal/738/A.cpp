#include<bits/stdc++.h>

using namespace std;

const int maxn=200;

int n,r[maxn];

char s[maxn];

int flag,last;

int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='o')
		{
			if(flag!=2)
				last=i;
			r[last]=i;
			flag=1;
		}
		else if(s[i]=='g')
		{
			if(flag==1)
				flag=2;
			else
				flag=0;
		}
		else
			flag=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]&&r[i]!=i)
			printf("***"),i=r[i];
		else
			printf("%c",s[i]);
	}
}