#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,ll> mp;
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n;i++)
	{
		string s;cin>>s;
		if(!mp.count(s)){
			mp[s]=0;
			cout<<"OK"<<endl;
		}
		else{
			cout<<s<<++mp[s]<<endl;
		}
	}
}