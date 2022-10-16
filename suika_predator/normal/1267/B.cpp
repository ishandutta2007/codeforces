#include<bits/stdc++.h>
using namespace std;
char s[300005];
int col[300005],num[300005],n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int tot=0,cou=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		{
			num[tot]=cou;cou=0;
			col[++tot]=s[i]-'A'+1;
		}
		cou++;
	}
	num[tot]=cou;
	bool ok=1;
	if(tot%2==0)
	{
		puts("0");
		return 0;
	}
	if(num[tot/2+1]<2)
	{
		puts("0");return 0;
	}
	for(int i=1;i<=tot;i++)
	{
		if(i==tot/2+1) continue;
		if(num[i]+num[tot-i+1]<=2||col[i]!=col[tot-i+1])
		{
			puts("0");return 0;
		}
	}
	cout<<num[tot/2+1]+1;
	return 0;
}