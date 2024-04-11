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
		int n;
		cin>>n;
		vector<int> nx(n+5);
		vector<int> vis(n+5);
		for(int i=1;i<=n;i++)
		{
			int t;
			cin>>t;
			nx[i]=(i-t);
		}
		int i;
		for(i=1;not vis[i];i=nx[i])
			vis[i]=1;
		vector<int> ans;
		for(;vis[i]!=2;i=nx[i])
		{
			ans.push_back(i);
			vis[i]=2;
		}
		cout<<ans.size()<<"\n";
		for(auto z:ans)
		{
			cout<<z<<' ';
		}
		cout<<"\n";
	}
	return 0;
}