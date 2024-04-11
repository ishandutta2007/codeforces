#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> v(n); for(auto &x : v)cin >> x;
	vector<ll> dif;
	deque<ll> dif2;
	for(int i = 0; i < n-1; ++i)dif.push_back(max(0ll,v[i]-v[i+1]) + (i ? dif.back() : 0));
	for(int i = n-1; i; --i)dif2.push_front(max(0ll,v[i]-v[i-1]) + (i == n-1 ? 0 : dif2[0]));
	for(int i = 0; i < m; ++i){
		ll a, b; cin >> a >> b;
		if(a < b)cout << dif[b-2] - (a-1 ? dif[a-2] : 0) << '\n';
		else cout << dif2[b-1] - (a == n ? 0 : dif2[a-1]) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}