#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;


void solve(){
	
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	sort(all(s));
	if(n == k){
		cout << s[k-1] << "\n";
		return;
	}
	if(s[0] == s[s.length()-1]){
		for(int i = 0; i < (n+k-1)/k; ++i){
			cout << s[0];
		}
		cout << "\n";
		return;
	}
	if(s[0] != s[k-1]){
		cout << s[k-1] << "\n";
		return;
	}
	if(s[k] == s[s.length()-1]){
		cout << s[0];
		for(int i = 1; i < (k-1+n)/k; ++i){
			cout << s[k];
		}
		cout << "\n";
		return;
	}
	cout << s[0] << s.substr(k,n-k) << "\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	int t; cin >> t; while(t--){
		solve();
	}
		
	return 0;
}