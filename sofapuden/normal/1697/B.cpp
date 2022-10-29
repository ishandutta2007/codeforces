#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<ll> v (n);for(auto &x : v)cin >> x;
	sort(v.begin(),v.end());
	vector<ll> pre(n);
	pre[0] = v[0];
	for(int i = 1; i < n; ++i){
		pre[i] = pre[i-1] + v[i];
	}
	while(q--){
		int a, b; cin >> a >> b;
		cout << pre[n-a+b-1]-(n-a ? pre[n-a-1] : 0) << '\n';
	}
}
 
int main(){
	int t = 1;
	while(t--)solve();
}