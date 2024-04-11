#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	string s; cin >> s;
	if(s[0] +s[1] +s[2] == s[3] + s[4] + s[5]){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	cout << '\n';
	//vector<int> v(n); for(auto &x : v) cin >> x;

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}