#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll q , n , f , lf;
	string s , ans;
	cin>>q;
	while(q > 0){
		f = 0;
		lf = -1;
		cin>>n>>s;
		for(ll i = n - 1 ; i >= 0 ; i--){
			if(s[i] % 2 == 1){
				lf = max(lf , i);
				f++;
			}
		}
		if(f <= 1){
			cout<<-1<<endl;
		} else {
			for(int i = 0 ; i <= lf ; i++){
				if(f % 2 == 1 && s[i] % 2 == 1){
					f--;
				} else if(s[i] % 2 == 1) {
					ans += s[i];
				}
			}
			cout<<ans<<endl;
		}
		ans.clear();
		q--;
	}
	return 0;
}