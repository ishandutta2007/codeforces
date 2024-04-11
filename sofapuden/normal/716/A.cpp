#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n, m; cin >> n >> m;
	int curr = 0;
	int ans = 0;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp;
		if(tmp -curr <= m){
			ans++;
		}
		else{
			ans = 1;
		}
		curr = tmp;
	}
	cout << ans << "\n";
			
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	solve();
		
	return 0;
}