#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int i,sum=0,fi=-1,ans=0;
		cin>>s;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='+')
				sum++;
			else
				sum--;
			if(sum==fi)
			{
				ans+=i+1;
				fi--;
			}
		}
		cout<<ans+s.size()<<endl;
	}
	return 0;
}