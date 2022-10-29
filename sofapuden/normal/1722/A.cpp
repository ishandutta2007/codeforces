#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	sort(s.begin(),s.end());
	string t = "Timur";
	sort(t.begin(),t.end());
	cout << (s == t ? "YES" : "NO") << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}