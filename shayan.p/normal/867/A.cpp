#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
int main()
{
	string s;
	ll n;
	cin>>n>>s;
	ll S=0,F=0;
	for(ll i=1;i<n;i++)
	{
		if(s[i]=='S'&&s[i-1]=='F')
		S++;
		if(s[i]=='F'&&s[i-1]=='S')
		F++;
	}
	if(F>S)
	cout<<"YES";
	else
	cout<<"NO";
}