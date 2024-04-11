#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		ll m,s=0;
		cin>>n>>m;
		vector<pair<int,int>> a(n);
		vector<int> ans;
		for (auto &[x,y]:a) cin>>x,y=++s;
		s=0;
		sort(a.begin(),a.end());reverse(a.begin(),a.end());
		for (auto [x,y]:a) if (s+x<=m) s+=x,ans.push_back(y);
		if (s<m+1>>1) cout<<"-1\n"; else
		{
			cout<<ans.size()<<'\n';
			sort(ans.begin(),ans.end());
			for (int x:ans) cout<<x<<' ';cout<<'\n';
		}
	}
}