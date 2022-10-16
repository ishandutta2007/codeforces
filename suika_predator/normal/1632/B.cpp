#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int len=1;
		while(len*2<n)len*=2;
		vector<int> ans;
		if(n%2==1)
		{
			ans.push_back(n-1);
			ans.push_back(n-1-len);
			int ty=0;
			for(int i=len;i<n-1;i++)
			{
				if(ty)
				{
					ans.push_back(i);
					ans.push_back(i-len);
				}
				else
				{
					ans.push_back(i-len);
					ans.push_back(i);
				}
				ty^=1;
			}
			for(int i=n-len;i<len;i++)
				ans.push_back(i);
		}
		else
		{
			int ty=0;
			for(int i=len;i<n;i++)
			{
				if(ty)
				{
					ans.push_back(i);
					ans.push_back(i-len);
				}
				else
				{
					ans.push_back(i-len);
					ans.push_back(i);
				}
				ty^=1;
			}
			for(int i=n-len;i<len;i++)
				ans.push_back(i);
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" \n"[i==n-1];
		}
	}
	
	return 0;
}