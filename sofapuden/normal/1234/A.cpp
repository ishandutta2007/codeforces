#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x). rend()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		ans+= tmp;
	}
	cout << ans/n+(ans%n?1:0) << "\n";
		
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t; 
	while(t--){
		solve();
	}	
}