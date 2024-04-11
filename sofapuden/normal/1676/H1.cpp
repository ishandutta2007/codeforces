#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

tree<pair<int,int>,null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	T.clear();
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	int ans = 0;
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