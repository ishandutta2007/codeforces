#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>a(n);
	map<int,int>cnt[2];
	int cur=0;
	nagai ans=0;
	for(int i=0;i<=n;++i){
		ans+=cnt[i%2][cur];
		++cnt[i%2][cur];
		if(i<n){
			int x;
			cin>>x;
			cur^=x;
		}
	}
	cout<<ans<<'\n';
	return 0;
}