#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define MP make_pair
#define F first
#define S second
using namespace std;
int main()
{
	ll n,A,s=0;cin>>n>>A;ll d[n];for(ll i=0;i<n;i++) {cin>>d[i];s+=d[i];}
	for(ll i=0;i<n;i++) {ll Min=n-1,Max=s-d[i];cout<<d[i]-(min(A-Min,d[i])-max(A-Max,(ll)1)+1)<<" ";}
}