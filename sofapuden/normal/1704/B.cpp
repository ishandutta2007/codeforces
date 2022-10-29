#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx = 1e9+7;

void solve(){
	int n, x; cin >> n >> x;
	int lo = mx, hi = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int a; cin >> a;
		lo = min(lo,a);
		hi = max(hi,a);
		if((hi-lo+1)/2 > x){
			ans++;
			lo = hi = a;
		}
	}
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();

}