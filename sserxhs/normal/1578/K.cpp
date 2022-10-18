#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vector<pair<string,int>> s(n);int cnt=0;
	for (auto &[x,y]:s) cin>>x,y=++cnt;
	sort(s.begin(),s.end(),[&](pair<string,int> x,pair<string,int> y)
	{
		for (int i=0;i<m;i++) if (x.first[i]^y.first[i])
		{
			return x.first[i]<y.first[i]^(i&1);
		}
		return 0;
	});
	for (auto &[x,y]:s) cout<<y<<' ';
}