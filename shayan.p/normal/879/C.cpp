#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
const ll maxn=6e5;
char cp[maxn];
ll num[maxn],n;
bool AND[20],XOR[20],OR[20];
bool what_happens(bool b,ll ind) //ind az chap
{
	ind=9-ind;
	for(ll i=0;i<n;i++)
	{
		if(cp[i]=='^') b=(b xor ((num[i]>>ind)%2));
		if(cp[i]=='&') b=(b && ((num[i]>>ind)%2));
		if(cp[i]=='|') b=(b || ((num[i]>>ind)%2));
	}
	return b;
}
ll make_num(bool *a)
{
	ll ans=0;
	for(ll i=0;i<10;i++) {ans*=2;ans+=a[i];}
	return ans;
}
ll type(ll x) {return (2*what_happens(1,x))+what_happens(0,x);}
int main()
{
	for(ll i=0;i<10;i++) AND[i]=1;
	cin>>n;for(ll i=0;i<n;i++) cin>>cp[i]>>num[i];
	for(ll i=0;i<10;i++) //ten digits  <1024
	{
		ll t=type(i);
		if(t==0) AND[i]=0;
		if(t==1) XOR[i]=1;
		if(t==3) OR[i]=1;
	}
	ll AND_=make_num(AND),OR_=make_num(OR),XOR_=make_num(XOR);
	cout<<3<<endl;
	cout<<"& "<<AND_<<endl;
	cout<<"| "<<OR_<<endl;
	cout<<"^ "<<XOR_;
}