#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

char neg(char k){
	if(k == '0'){
		return '1';
	}
	return '0';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool a = true;
		string s , ans;
		cin>>s;
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] != s[i - 1]){
				a = false;
				break;
			}
		}
		if(a == true){
			cout<<s<<endl;
		} else {
			ans += s[0];
			for(int i = 1 ; i < s.size() ; i++){
				if(s[i] == s[i - 1]){
					ans += neg(s[i]);
				}
				ans += s[i];
			}
			cout<<ans<<endl;
		}
		s.clear();
		ans.clear();
	}
	return 0;
}