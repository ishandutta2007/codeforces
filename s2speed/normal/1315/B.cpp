#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , a , b , p;
	string s;
	cin>>t;
	while(t > 0){
		cin>>a>>b>>p>>s;
		if(s[s.size() - 2] == 'A'){
			p -= a;
		} else {
			p -= b;
		}
		if(p < 0){
			cout<<s.size()<<endl;
		}
		for(int i = s.size() - 3 ; i >= 0 && p >= 0 ; i--){
			if(s[i] != s[i + 1]){
				if(s[i] == 'A'){
					p -= a;
				} else {
					p -= b;
				}
			}
			if(p < 0){
				cout<<i + 2<<endl;
			}
		}
		if(p >= 0){
			cout<<1<<endl;
		}
		t--;
	}
	return 0;
}