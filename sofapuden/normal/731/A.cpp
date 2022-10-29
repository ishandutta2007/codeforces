#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	int curr = 'a';
	int ans = 0;
	int len = s.length();
	for(int i = 0; i < len; ++i){
		ans += min(26-abs(curr-s[i]),abs(curr-s[i]));
		curr = s[i];
	}
	cout << ans;
		
			
}