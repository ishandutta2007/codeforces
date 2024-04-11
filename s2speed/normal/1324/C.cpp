#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t > 0){
		ll m = 0 , counter = 0;
		string s;
		cin>>s;
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == 'L'){
				counter++;
			} else {
				m = max(m , counter);
				counter = 0;
			}
		}
		m = max(m , counter);
		cout<<m + 1<<endl;
		t--;
	}
	return 0;
}