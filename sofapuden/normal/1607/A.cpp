#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const double PI = acos(-1);

void solve(){
	map<char,int> M;
	for(int i = 0; i < 26; ++i){
		char c; cin >> c;
		M[c] = i+1;
	}
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size()-1; ++i){
		ans+=abs(M[s[i]]-M[s[i+1]]);


	}
	cout << ans << '\n';


}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--){
		solve();
	}
}