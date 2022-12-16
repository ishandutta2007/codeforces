/*#include<bits/stdc++.h>
#define ll int
#define PB push_back
using namespace std;
const ll maxn=2*1e7;
bool check[maxn];
ll ans[maxn];
ll rev_ans[maxn];
ll mxp=1988;

/////
ll process(ll x)
{
	ll y=x,num=0,ten=1;
	while(y!=0)
	{
		num+=(y%10)*ten;y/=10;
		if(!check[num]) {check[num]=1;return num;}
		ten*=10;
	}
}
ll make_int(string s)
{
	ll x=0;for(ll i=0;i<s.size();i++) {x*=10;x+=s[i]-'0';} return x;
}
int main(){
	for(ll i=1989;i<maxn;i++) {ans[i]=process(i);rev_ans[ans[i]]=i;}
	int n;cin>>n;
	for(ll i=0;i<n;i++)
	{
		string s;cin>>s;
		cout<<rev_ans[make_int(s.substr(4))]<<endl;
	}
}*/




/*
//Design Tutorial: Inverse the Problem
#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define S second
#define F first
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
const ll maxn=2010;
ll n;ll d[maxn][maxn];
bool check(vector<ll> &v)
{
	if(v.size()<2) return 1;
	pll p;ll Min=1e18;vector<ll> v1,v2;
	for(ll i=0;i<v.size();i++)
		for(ll j=0;j<v.size();j++)
		if(i!=j) if(Min>d[v[i]][v[j]]) {Min=d[v[i]][v[j]];p=MP(v[i],v[j]);}
	for(ll i=0;i<v.size();i++) // p.F ans p.S are not included
	{
		if(v[i]==p.F||v[i]==p.S) continue;
		if(d[v[i]][p.F]==d[v[i]][p.S]) return 0;
		else if(d[v[i]][p.F]<d[v[i]][p.S]) {if(d[v[i]][p.S]-d[v[i]][p.F]==d[p.F][p.S]) v1.PB(v[i]);else return 0;}
		else {if(d[v[i]][p.F]-d[v[i]][p.S]==d[p.F][p.S]) v2.PB(v[i]);else return 0;}
	}
	for(ll i=0;i<v1.size();i++)
		for(ll j=0;j<v2.size();j++)
		if(d[v1[i]][p.F]+d[p.F][p.S]+d[p.S][v2[j]]!=d[v1[i]][v2[j]]) return 0;
		return check(v1)&&check(v2);
}
int main()
{
	vector<ll> v;
	ll n;cin>>n;for(ll i=0;i<n;i++) v.PB(i);
	for(ll i=0;i<n;i++) 
		for(ll j=0;j<n;j++) 
		cin>>d[i][j];
	for(ll i=0;i<n;i++) 
		for(ll j=0;j<n;j++)
		if((d[i][j]<0||(i!=j&&d[i][j]==0))||(i==j&&d[i][i]!=0)||(i!=j&&d[i][j]!=d[j][i])) {cout<<"NO";return 0;}
	if(check(v)) cout<<"YES";
	else cout<<"NO";
}*/

#include<bits/stdc++.h>
#define ll long long
#define PB push_back
#define S second
#define F first
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
ll FOUR,TWO,ONE;
bool pos(ll four,ll two,ll one)
{
	ll F=FOUR,T=TWO,O=ONE;
	ll x=min(F,four);four-=x;F-=x;
	two+=four;T+=F*2;
	x=min(T,two);two-=x;T-=x;
	one+=two;O+=2*T;
	if(one>=O) return 1;
	return 0;
}
int main()
{
	ll n,k;cin>>n>>k;
	for(ll i=0;i<k;i++) {ll a;cin>>a;FOUR+=a/4;a=a%4;TWO+=a/2;ONE+=a%2;}
	for(ll i=0;i<=n;i++) // tedad eshteraki do ghabile
		if(pos(n-i,i+2*n,i)) {cout<<"YES";return 0;}
		cout<<"NO";
}