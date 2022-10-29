#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	for(int i = 0; i  < n; ++i){
		int ans = 0;
		int curr = 0;
		bool ok = 0;
		string s; cin >> s;
		for(char c : s){
			if(c == '0'){
				curr++;
			}
			else{
				if(ok){
					ans+= curr;
				}
				curr = 0;
				ok = 1;
			}
		}
		cout << ans << "\n";
	}
}