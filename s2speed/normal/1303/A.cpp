#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
 
int main(){
	string s;
	ll t;
	cin>>t;
	while(t > 0){
		cin>>s;
		int h = -1 , counter = 0 , x = -1;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == '1'){
				h = i;
				break;
			}
		}
		for(int i = s.size() - 1 ; i >= 0 ; i--){
			if(s[i] == '1'){
				x = i;
				break;
			}
		}
		if(h == -1){
			cout<<0<<endl;
			t--;
			continue;
		}
		for(int i = h ; i <= x ; i++){
			if(s[i] == '0'){
				counter++;
			}
		}
		cout<<counter<<endl;
		t--;
	}
	return 0;
}