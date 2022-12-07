#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n;
char s[N];
int val[20];
int main()
{
	int i,j,x;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='L') 
		{
			for(j=0;j<10;j++)
			{
				if(val[j]==0) 
				{
					val[j]=1;break;
				}
			}
		}
		else if(s[i]=='R')
		{
			for(j=9;j>=0;j--)
			{
				if(val[j]==0)
				{
					val[j]=1;break;
				}
			}
		}
		else 
		{
			x=s[i]-'0';
			val[x]=0;
		}
	}
	for(i=0;i<10;i++) printf("%d",val[i]);
	return 0;
}