#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pl4 pair<pll,pll>
#define S second
#define F first
#define PB push_back
#define MP make_pair
using namespace std;
ll bin,x,y,a,b;
const ll maxn=1e9;
ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
void binary(ll f,ll s)
{
	if(f>s) return;
	ll mid=(f+s)/2;
	if(mid*x<=a&&mid*y<=b){bin=mid;binary(mid+1,s);}
	else binary(f,mid-1);
}
int main()
{
cin>>a>>b>>x>>y;
ll g=gcd(x,y);x=x/g;y=y/g;
binary(0,maxn);
cout<<bin*x<<" "<<bin*y;
}