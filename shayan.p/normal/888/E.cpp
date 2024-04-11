#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
set<ll> st;
vector<ll>v1,v2;
ll a[50];
ll Max,bin,n,m;
void precom(vector<ll> &v,ll f,ll s)
{
	st.clear();
	st.insert(0);
	v.PB(0);
	for(ll i=f;i<s;i++)
	{
		ll sz=v.size();
		for(ll j=0;j<sz;j++)
		{
		ll num=(a[i]+v[j])%m;
		if(!st.count(num)){st.insert(num);v.PB(num);Max=max(Max,num);}
		}
	}
}
void Band(ll x,ll f=0,ll s=v2.size()-1)//bozorg tarin meghdar ghabl az band < not <=
{
	if(f>s)return;
	ll mid=(f+s)/2;
	if(v2[mid]<x){bin=max(bin,v2[mid]);Band(x,mid+1,s);}
	else Band(x,f,mid-1);
}
int main()
{
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>a[i];
	precom(v1,0,n/2);
	precom(v2,n/2,n);
	sort(v2.begin(),v2.end());
	for(ll i=0;i<v1.size();i++){bin=0;Band(m-v1[i]);Max=max(Max,v1[i]+bin);}
	cout<<Max;
}