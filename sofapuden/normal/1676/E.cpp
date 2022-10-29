#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	int n; cin >> n;
	int q; cin >> q;
	vector<int> v(n); for(auto &x : v)cin >> x;
	sort(v.rbegin(),v.rend());
	for(int i = 1; i < n; ++i){
		v[i] += v[i-1];
	}
	while(q--){
		int x; cin >> x;
		if(lower_bound(v.begin(),v.end(),x) == v.end()){
			cout << -1 << '\n';
		}
		else{
			cout << lower_bound(v.begin(),v.end(),x) - v.begin() + 1<< '\n';
		}

	}
}

int main(){

	int t; cin >> t;
	while(t--)solve();

}