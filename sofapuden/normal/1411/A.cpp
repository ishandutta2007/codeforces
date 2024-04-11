#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		int cn = 0;
		for(int i = n-1; i >= 0; --i){
			if(s[i] == ')')cn++;
			else break;
		}
		cout << (cn*2 > n ? "Yes" : "No") << "\n";

	}
}