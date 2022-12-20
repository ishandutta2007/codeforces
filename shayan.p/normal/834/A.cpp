#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll und()
{
	char ch;cin>>ch;
	if(ch=='v')return 0;
	if(ch=='<')return 1;
	if(ch=='^')return 2;
	if(ch=='>')return 3;
}
int main()
{
	ll a=und(),b=und();
	ll n;cin>>n;n%=4;
	if((a+n)%4==b&&(b+n)%4==a)cout<<"undefined";
	else if((a+n)%4==b)cout<<"cw";
	else if((b+n)%4==a)cout<<"ccw";
}