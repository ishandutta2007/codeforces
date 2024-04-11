#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	string s, t; cin >> s >> t;
	if(t == "a"){
		cout << 1 << '\n';
		return;
	}
	for(auto x : t){
		if(x == 'a'){
			cout << "-1\n";
			return;
		}
	}
	cout << (1ll<<s.size()) << '\n';
}

int main(){
	int tes; cin >> tes;
	while(tes--)solve();
}