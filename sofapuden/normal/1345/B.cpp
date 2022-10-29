#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n; cin >> n;
	if(n == 1){
		cout << 0 << "\n";
		return;
	}
	n-=2;
	int amo = 2;
	int ans = 1;
	while(n > 1){
		if(amo*3-1 <= n){
			n-= amo*3-1;
			amo++;
		}
		else{
			amo = 2;
			n-= 2;
			ans++;
		}
	}
	cout << ans << "\n";
		
		
		
		
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}