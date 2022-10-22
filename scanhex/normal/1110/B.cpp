#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>a(n);
	for(auto&x:a)cin>>x;
	vector<int>mem;
	for(int i=0;i+1<n;++i)
		mem.push_back(a[i+1]-a[i]-1);
	int ans=a.back()-a[0]+1;
	sort(mem.rbegin(),mem.rend());
	for(int i=0;i<min((int)mem.size(),k-1);++i)
		ans-=mem[i];
	cout<<ans<<'\n';
	return 0;
}