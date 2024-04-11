#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
#define pll pair<ll,ll>
using namespace std;
string s;
ll f(char c)
{
	ll last=-1,ans=1;
	for(ll i=0;i<s.size();i++)if(s[i]==c){ans=max(ans,i-last);last=i;}
	ans=max(ans,s.size()-last);
	return ans;
}
int main()
{
	cin>>s;
	ll Min=s.size();
	for(ll i=int('a');i<=int('z');i++)Min=min(Min,f(char(i)));
	cout<<Min;
}