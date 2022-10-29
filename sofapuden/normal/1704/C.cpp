#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx = 1e9+7;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> v(m);
	for(auto &x : v)cin >> x;
	sort(v.begin(),v.end());
	vector<int> dif;
	for(int i = 1; i < m; ++i){
		dif.push_back(v[i]-v[i-1]-1);
	}
	dif.push_back(n-v.back()+v[0]-1);
	sort(dif.rbegin(),dif.rend());
	int ans = 0;
	for(int i = 0; i < m; ++i){
		if(dif[i]-4*i == 1)ans++;
		ans+=max(0,dif[i]-4*i-1);
	}
	cout << n-ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while(t--)solve();

}