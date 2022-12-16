#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
ll num[5];
int main()
{
	ll n;string s;cin>>n>>s;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='U')num[0]++;
		if(s[i]=='D')num[1]++;
		if(s[i]=='L')num[2]++;
		if(s[i]=='R')num[3]++;
	}
	cout<<n-(abs(num[0]-num[1])+abs(num[2]-num[3]));
}