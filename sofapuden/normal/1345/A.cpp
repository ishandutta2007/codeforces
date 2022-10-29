#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int a, b; cin >> a >> b;
	if(a == 2 && a == b){
		cout << "YES\n";
		return;
	}
	if(a == 1 || b == 1){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}