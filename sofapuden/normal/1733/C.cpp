#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	if((v[0]^v[n-1])&1)v[n-1] = v[0];
	else v[0] = v[n-1];
	cout << n-1 << '\n';
	if(n != 1)cout << 1 << ' ' << n << '\n';
	for(int i = 1; i < n-1; ++i){
		if((v[0]^v[i])&1)cout << 1 << ' ' << i+1 << '\n';
		else cout << i+1 << ' ' << n << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}