#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[23333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>(s+1);
		n=strlen(s+1);
		int ans=114514;
		for(int i=0;i<=n;i++)
		{
			int cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(s[j]=='0'&&j<=i)cnt++;
				if(s[j]=='1'&&j>i)cnt++;
			}
			ans=min(ans,cnt);
			cnt=0;
			for(int j=1;j<=n;j++)
			{
				if(s[j]=='1'&&j<=i)cnt++;
				if(s[j]=='0'&&j>i)cnt++;
			}
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}