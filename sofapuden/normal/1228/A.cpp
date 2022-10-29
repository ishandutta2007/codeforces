#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;


bool def(string s){
	set<char> sc;
	for(char c : s){
		sc.insert(c);
	}
	return sc.size() == s.size();
}

void solve(){
	
	int l, r; cin >> l >> r;
	for(int i = l; i <= r; ++i){
		if(def(to_string(i))){
			cout << i << "\n";
			return;
		}
	}
	cout << "-1\n";
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	solve();
		
	return 0;
}