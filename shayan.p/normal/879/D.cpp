#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
const ll maxn=1e5+10;
ll ans,a[maxn],anum[maxn],kam;
int main()
{
	ll n,k,m;cin>>n>>k>>m;
	stack<ll> s;
	stack<ll> snum;
	for(ll i=0;i<n;i++)
	{
		ll x;cin>>x;
		if(s.empty()||s.top()!=x) {snum.push(1);s.push(x);}
		else {ll y=snum.top();snum.pop();snum.push(y+1);}
		if(snum.top()%k==0) {s.pop();snum.pop();} 
	}
	ll sz=s.size();
	for(ll i=sz-1;i>=0;i--){a[i]=s.top();anum[i]=snum.top();s.pop();snum.pop();}
	ll beg=0,en=sz-1;//akharini ke darimesh
	for(en=sz-1;en>beg;en--) //halat i==beg dasti barrasi she
	{
		if(a[beg]!=a[en]) break;
		kam+=(anum[beg]+anum[en])-((anum[beg]+anum[en])%k);
		if((anum[beg]+anum[en])%k==0) beg++;
		else break;
	}
	if(beg==en)
	{
		ll up=en+1,down=en-1,num_mid;
		num_mid=((anum[en])*m)%k;
		if(num_mid==0)
		{
			ll j;
			for(j=1;en-j>=0&&en+j<sz;j++)
			{
			if(a[en-j]!=a[en+j]) break;
			if((anum[en-j]+anum[en+j])%k!=0) {num_mid=(anum[en-j]+anum[en+j])%k;break;}
			}
			up=en+j;down=en-j;
		}
		for(ll q=0;q<=down;q++) ans+=anum[q];
		for(ll q=sz-1;q>=up;q--) ans+=anum[q];
		ans+=num_mid;
	}
	else
	{
		for(ll j=0;j<sz;j++) ans+=anum[j];
		ans*=m;ans-=(m-1)*kam; //overflow?
	}
	cout<<ans;
}