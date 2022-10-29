#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n; ++i){
		if(i > n-3)cout << (char)(s[i]-'1' + 'a');
		else{
			if(s[i+2] == '0' && (i+3 == n || s[i+3] != '0')){
				cout << (char)(stoi(s.substr(i,2)) + 'a' - 1);
				i+=2;
			}
			else cout << (char)(s[i]-'1' + 'a');
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();

}