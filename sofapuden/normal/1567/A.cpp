#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		for(char  c : s){
			if(c == 'U')cout << 'D';
			else if(c == 'D')cout << 'U';
			else{
				cout << c;
			}
		}
		cout << '\n';
	}

}