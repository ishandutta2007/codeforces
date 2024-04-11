#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const ll maxn=1e5+10,maxsg=4e5+10,inf=1e18;
ll Gcd[maxsg],cnt[maxsg],GCD,Cnt,n;
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
void upd(ll ind,ll val,ll id=1,ll l=1,ll r=n)
{
//	cout<<ind<<" "<<val<<" "<<id<<" "<<l<<" "<<r<<endl;
	if(l>r)return;
	if(ind<l||r<ind)return;
	ll GCD=gcd(Gcd[id],val);
//	cout<<ind<<" "<<val<<" "<<id<<" "<<l<<" "<<r<<"	"<<GCD<<endl;
	if(Gcd[id]==GCD)cnt[id]+=(val==GCD);
	else cnt[id]=(val==GCD);
	Gcd[id]=GCD;
	if(l==r)return;
	ll mid=(l+r)/2;
	upd(ind,val,2*id,l,mid);
	upd(ind,val,2*id+1,mid+1,r);
}
void ask(ll f,ll s,ll id=1,ll l=1,ll r=n)
{
	if(l>r) return;
	if(s<l||r<f)return;
	if(f<=l&&r<=s)
	{
		ll GCDx=gcd(Gcd[id],GCD);
		if(GCD==GCDx)Cnt+=((Gcd[id]==GCDx)?cnt[id]:0);
		else Cnt=((Gcd[id]==GCDx)?cnt[id]:0);
		GCD=GCDx;
		return;
	}
	if(l==r)return;
	ll mid=(l+r)/2;
	ask(f,s,2*id,l,mid);
	ask(f,s,2*id+1,mid+1,r);
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++){ll x;cin>>x;upd(i,x);}
	ll t;cin>>t;
	for(ll i=0;i<t;i++)
	{
		ll a,b;cin>>a>>b;
		GCD=0;Cnt=0;ask(a,b);
		cout<<(b-a+1)-Cnt<<endl;
	}
}