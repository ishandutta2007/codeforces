#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int main(){
	string s;cin>>s;
	bool a=(s[0]=='a'||s[0]=='h');
	bool b=(s[1]=='1'||s[1]=='8');
	bool c=a&&b;
	if(c)cout<<3;
	else if(a||b)cout<<5;
	else cout<<8;
}