#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
const ll maxn=1e5+10,inf=1e18+100;
ll sz[maxn];
string s,s1,s2;
char f(ll n,ll k){
	if(k>sz[n])return '.';
	if(n==0)return s[k-1];
	if(k<=33)return s1[k-1];
	if(k==34)return '"';
	if(k<=34+sz[n-1])return f(n-1,k-34);
	if(k==34+sz[n-1]+1)return '"';
	k-=(35+sz[n-1]);
	if(k<=30)return s2[k-1];
	if(k==31)return '"';
	if(k<=31+sz[n-1])return f(n-1,k-31);
	if(k==32+sz[n-1])return '"';
	return '?';
}
int main(){
	s="What are you doing at the end of the world? Are you busy? Will you save us?";
	s1="What are you doing while sending ";
	s2="? Are you busy? Will you send ";
	sz[0]=75;for(ll i=1;i<54;i++)sz[i]=2*sz[i-1]+68;
	for(ll i=54;i<maxn;i++)sz[i]=inf;
	ll q;cin>>q;
	vector<char>v;
	for(ll i=0;i<q;i++){
		ll n,k;cin>>n>>k;v.PB(f(n,k));
	}
	for(ll i=0;i<v.size();i++)cout<<v[i];
}