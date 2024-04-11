#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll s=0,n,x;cin>>n>>x;
	for(ll i=0;i<n;i++) {ll q;cin>>q;s+=q;}
	s+=(n-1);
	if(s==x) cout<<"YES";
	else cout<<"NO";
}