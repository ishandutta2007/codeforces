#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,Q;
char s[N];
int a[N][30];
int main()
{
	int i,j,l,r,cnt;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			a[i][j]=a[i-1][j];
		}
		a[i][s[i]-'a']++;
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		cnt=0;
		for(i=0;i<26;i++)
		{
			if(a[r][i]-a[l-1][i]>0) cnt++;
		}
		if(l==r) puts("Yes");
		else 
		{
			if(cnt==1) puts("No");
			else if(cnt==2)
			{
				if(s[l]==s[r]) puts("No");
				else puts("Yes");
			}
			else puts("Yes");
		}
	}
	return 0;
}