#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	ll q;cin>>q;
	for(ll i=0;i<q;i++){
		ll n;cin>>n;
		if(n==1||n==2||n==3||n==5||n==7||n==11)cout<<-1;
		else{
			if(n%4==0)cout<<n/4;
			if(n%4==1)cout<<((n-9)/4)+1;
			if(n%4==2)cout<<((n-6)/4)+1;
			if(n%4==3)cout<<((n-15)/4)+2;
		}
		cout<<endl;
	}
}