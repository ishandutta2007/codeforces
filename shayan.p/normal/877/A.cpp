#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
string s;
ll look_for(string &str){
	ll ans=0;
	for(ll i=0;i<s.size();i++){
		bool is=1;
		for(ll j=0;j<str.size();j++){
			if(i+j>=s.size()){
				is=0;
				break;
			}
			if(s[i+j]!=str[j]){
				is=0;
				break;
			}
		}
		ans+=is;
	}
	return ans;
}
int main(){
	string s1="Danil",s2="Olya",s3="Slava",s4="Ann",s5="Nikita";
	cin>>s;
	ll num=0;
	num+=look_for(s1);
	num+=look_for(s2);
	num+=look_for(s3);
	num+=look_for(s4);
	num+=look_for(s5);
	if(num==1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}