#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int amount = 0;
	int ans = 0;
	for(char c:s){
		if(c == 'x'){
			amount++;
		}
		else{
			ans += max(0,amount-2);
			amount = 0;
		}
	}
	ans += max(0,amount-2);
	cout << ans;
			
}