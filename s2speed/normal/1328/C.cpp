#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t > 0){
		bool b = false;
		ll n;
		string s , h , r;
		cin>>n>>s;
		h += "1";
		r += "1";
		for(int i = 1 ; i < n ; i++){
			if(s[i] == '2' && b == false){
				h += "1";
				r += "1";
			} else if(s[i] == '0'){
				h += "0";
				r += "0";
			} else if(s[i] == '1' && b == false){
				h += "1";
				r += "0";
				b = true;
			} else if(s[i] == '1' && b == true) {
				h += "0";
				r += "1";
			} else {
				h += "0";
				r += "2";
			}
		}
		cout<<h<<endl<<r<<endl;
		h = "";
		r = "";
		t--;
	}
	return 0;
}