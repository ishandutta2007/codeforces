#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s;cin>>s;ll x=0;bool check=0;
	for(ll i=0;i<s.size();i++) {if(!check&&s[i]=='1')check=1;if(check&&s[i]=='0')x++;}
	if(x>=6) cout<<"yes";
	else cout<<"no";
}