#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
string s;ll k;
bool pal(ll i,ll j){
	while(s[i]==s[j]&&i<=j){
		i++;
		j--;
	}
	if(i>j)return 1;
	return 0;
}
int main(){
	cin>>s>>k;
	if(s.size()%k!=0){
		cout<<"NO";
		return 0;
	}
	ll num=s.size()/k;
	for(ll i=0;i<s.size();i+=num){
		if(pal(i,i+num-1)==0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}