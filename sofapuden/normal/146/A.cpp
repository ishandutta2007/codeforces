#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int x1 = 0, x2 = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] != '4' && s[i] != '7'){
			cout << "NO\n";
			exit(0);
		}
		if(i < n/2){
			x1+=s[i]-'0';
		}
		else{
			x2+=s[i]-'0';
		}
	}
	if(x1 == x2)cout << "YES\n";
	else cout << "NO\n";
}