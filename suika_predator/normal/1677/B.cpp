#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<int> sum((n+1)*(m+1));
		for(int i=0;i<n*m;i++)
		{
			if(i==0)sum[i]=s[i]-'0';
			else sum[i]=sum[i-1]+s[i]-'0';
		}
		vector<int> ans(n*m);
		vector<int> vis(m);
		int cnt0=0;
		for(int i=0;i<n*m;i++)//col
		{
			if(s[i]-'0')
			{
				if(not vis[i%m])
					vis[i%m]=1,cnt0++;
			}
			ans[i]=cnt0;
		}
//		for(auto z:ans)cerr<<z<<' ';
//		cerr<<"\n";
		for(int i=0;i<m;i++)//row
		{
			int cnt=(sum[i]!=0);
			for(int j=i;j<n*m;j+=m)
			{
				ans[j]+=cnt;
				cnt+=(sum[j+m]-sum[j]!=0);
			}
		}
		for(auto z:ans)cout<<z<<' ';
		cout<<"\n";
	}
	
	return 0;
}