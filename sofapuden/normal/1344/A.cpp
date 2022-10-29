#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n; cin >> n;
	set<int> s;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		s.insert(((tmp+i)%n+n)%n);
	}
	if(s.size() == n){
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