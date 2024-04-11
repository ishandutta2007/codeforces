#include<bits/stdc++.h>
using namespace std;
using nagai=long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>p(n);
	for(auto&x:p)cin>>x;
	vector<int>s(n);
	for(auto&x:s)
		cin>>x,--x;
	vector<int>c(k);
	for(auto&x:c)cin>>x,--x;
	vector<vector<pair<int,int>>>mem(m);
	for(int i=0;i<n;++i)mem[s[i]].push_back({p[i],i});
	for(auto&x:mem)sort(x.rbegin(),x.rend());
	int ans=0;
	for(int x:c)
		if(x!=mem[s[x]].front().second)
			++ans;
	cout<<ans<<'\n';
	return 0;
}