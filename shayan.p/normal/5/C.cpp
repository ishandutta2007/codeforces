#include<bits/stdc++.h>
#define ll long long
#define PB push_back
using namespace std;
const ll maxn=1e6+10;
ll last[maxn];
int main()
{
	string str;cin>>str;
	stack<ll>s;
	for(ll i=0;i<str.size();i++)
	{
		if(str[i]==')'&&!s.empty()){last[s.top()]=i;s.pop();}
		else s.push(i);
	}
	vector<ll> v;
	for(ll i=0;i<str.size();i++)
	{
		ll cnt=0;
		while(str[i]=='('&&last[i]!=0&&i<str.size())
		{
			cnt+=last[i]-i+1;
			i=last[i]+1;
		}
		if(cnt==0)continue;
		v.PB(cnt);
		i--;
	}
	if(v.size()==0){cout<<0<<" "<<1;return 0;}
	ll cnt=0,Max=0;
	for(ll i=0;i<v.size();i++)
	{
		if(v[i]>Max){
			Max=v[i];
			cnt=0;
		}
		if(v[i]==Max)cnt++;
	}
	cout<<Max<<" "<<cnt;
}