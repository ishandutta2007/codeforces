#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	set<int> s;
	for(int i = 0; i < n; ++i){
		s.insert(v[i]);
	}
	cout << s.size() - ((n^s.size())&1) << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}