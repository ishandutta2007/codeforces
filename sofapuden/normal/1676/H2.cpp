#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

tree<pair<ll,ll>,null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	T.clear();
	int n; cin >> n;
	vector<ll> v(n);
	for(auto &x : v)cin >> x;
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		ans += T.size()-T.order_of_key({v[i]-1,i});
		T.insert({v[i],i});
	}
	cout << ans << '\n';
}

int main(){

	int t; cin >> t;
	while(t--)solve();

}