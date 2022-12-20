#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
ll a,b,differ,sz,XOR,n,x,y;
bool dif[11];
bool ask(ll ind)
{
	vector<ll>v;
	for(ll j=1;j<=n;j++)if((j>>ind)%2==0)v.PB(j);//v oonhaii ro dare ke ragham i omeshoon
	if(v.empty())return 0;
	cout<<"? "<<v.size();for(ll i=0;i<v.size();i++)cout<<" "<<v[i];cout<<endl;
	ll num;cin>>num;
	if(num==XOR||num==y)differ=ind;
	return (num==XOR||num==y);
}
bool ask(ll ind1,ll ind2)//both zero__if the 0 0 has an answer return 0
{
	vector<ll>v;
	for(ll j=1;j<=n;j++)if(((j>>ind1)%2==0)&&((j>>ind2)%2==0))v.PB(j);
	if(v.empty())return 1;
	cout<<"? "<<v.size();for(ll i=0;i<v.size();i++)cout<<" "<<v[i];cout<<endl;
	ll num;cin>>num;
	return !(num==XOR||num==y);
}
ll lg(ll num){if(num==1)return 1;return 1+lg(num/2);}
int main()
{
	cin>>n>>x>>y;
	sz=lg(n);XOR=(x xor y);
	for(ll i=0;i<sz;i++)dif[i]=ask(i);
	b+=(1<<differ);
	for(ll i=0;i<sz;i++)
	{
		if(i==differ)continue;
		bool check=ask(i,differ);
		if(dif[i])
		{
			if(check&&dif[i])a+=(1<<i);
			else b+=(1<<i);
		}
		else if(check){a+=(1<<i);b+=(1<<i);}
	}
	cout<<"! "<<a<<" "<<b;
}