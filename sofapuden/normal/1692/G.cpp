#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	int cu = 0;
	for(int i = 1; i < k+1; ++i){
		if(v[i]*2 <= v[i-1])cu++;
	}
	int ans = (cu == 0);
	for(int i = k+1; i < n; ++i){
		if(v[i]*2 <= v[i-1])cu++;
		if(v[i-k]*2 <= v[i-k-1])cu--;
		if(!cu)ans++;
	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}