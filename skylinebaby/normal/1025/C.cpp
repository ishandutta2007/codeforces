#include<bits/stdc++.h>
using namespace std;
char s[111111];
int x[211111];
int main()
{
	int n;
	cin>>s;
	n = strlen(s);
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		if (s[i]=='b') x[i] = 1;
		else x[i] = 0;
		//printf("%d",x[i]);
	}
	for(int i = 0;i<n;i++)
	{
		if (s[i]=='b') x[i+n] = 1;
		else x[i+n] = 0;	
		//printf("%d",x[i+n]);	
	}
	
	int cur = 0;
	while(cur<2*n-1)
	{
		int pos = 1;
		while(cur<2*n-1&&x[cur]^x[cur+1]==1)
		{
			pos ++;
			cur ++;
		}
		cur++;
		ans = max(ans,pos);
	}
	ans = min(ans,n);
	printf("%d\n",ans);
	return 0;
}