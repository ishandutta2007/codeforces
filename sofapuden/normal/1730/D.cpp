#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	set<pair<char,char>> S;
	for(int i = 0; i < n; ++i){
		pair<char,char> cu = {min(s1[i],s2[n-i-1]), max(s1[i],s2[n-i-1])};
		if(S.count(cu))S.erase(cu);
		else S.insert(cu);
	}
	if(S.size() > 1){
		cout << "NO\n";
	}
	else if(!S.size()){
		cout << "YES\n";
	}
	else{
		if(S.begin()->first == S.begin()->second){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}