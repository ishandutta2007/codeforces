#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n; cin >> n;
	int ans = 0;
	for(int i = 1; i <= n/2; ++i){
		ans += pow(2,i);
	}
	cout << ans << "\n";
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}