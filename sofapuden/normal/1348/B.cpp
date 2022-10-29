#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	
	int n, k; cin >> n >> k;
	
	
	vi v(k, 1);
	set<int> s; 
	bool bad = 0;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		if(s.count(tmp) == 0){
			s.insert(tmp);
			if((int)s.size() > k){
				bad = 1;
			}
			else{
				v[s.size()-1] = tmp;
			}
		}
	}
	if(bad){
		cout << -1 << "\n";
		return;
	}
	
	cout << 100*k << "\n";
	for(int i = 0; i < 100; ++i){
		for(int j : v){
			cout << j << " ";
		}
	}
	cout << "\n";
	
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}