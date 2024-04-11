#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.size();
		for(int i = 0; i < n; ++i){
			if(i&1){
				cout << (s[i] == 'z' ? 'y' : 'z');
			}
			else{
				cout << (s[i] == 'a' ? 'b' : 'a');
			}
		}
		cout << "\n";
	}
}