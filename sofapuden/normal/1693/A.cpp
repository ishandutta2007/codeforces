#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n; cin >> n;
	vector<ll> v(n); for(auto &x : v)cin >> x;
	bool ok = 0;
	for(int i = n-1; i; --i){
		if(v[i] > 0 || (ok && v[i] >= 0)){
			cout << "No\n";
			return;
		}
		if(v[i] != 0)ok = 1;
		v[i-1]+=v[i];
	}
	if(v[0]){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}