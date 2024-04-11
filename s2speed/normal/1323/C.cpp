#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n , a = 0 , b = 0 , co = 0 , counter = 0;
	string s;
	cin>>n>>s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '('){
			a++;
		} else {
			b++;
		}
	}
	if(a != b){
		cout<<-1<<endl;
		return 0;
	}
	bool al = false;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '('){
			co++;
		} else {
			co--;
		}
		if(co < 0 && al == false){
			al = true;
			
		}
		if(al == true){
			counter++;
		}
		if(al == true && co == 0){
			al = false;
		}
	}
	cout<<counter<<endl;
	return 0;
}