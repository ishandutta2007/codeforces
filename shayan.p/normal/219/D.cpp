#include<bits/stdc++.h>
#define PB push_back
#define ll long long
using namespace std;
const ll maxn=2e5+10;
ll dp[maxn],Ans[maxn],n;
bool mark[maxn],mark2[maxn];
vector<ll> in[maxn],out[maxn];
void dfs(ll a) // node number a
{
	if(mark[a]) return;
	ll ans=0;
	mark[a]=1;
	for(ll i=0;i<out[a].size();i++)
	{
		ll y=out[a][i];
		if(mark[y]) continue;
		dfs(y);
		ans+=dp[y];
	}
	for(ll i=0;i<in[a].size();i++)
	{
		ll y=in[a][i];
		if(mark[y]) continue;
		ans++;
		dfs(y);
		ans+=dp[y];
	}
	dp[a]=ans;
}
void calc_ans(ll a)//for children
{
	mark2[a]=1;
	for(ll i=0;i<out[a].size();i++)
	{
		ll y=out[a][i];
		if(mark2[y]) continue;
		Ans[y]=Ans[a]+1;// +1
		calc_ans(y);
	}
	for(ll i=0;i<in[a].size();i++)
	{
		ll y=in[a][i];
		if(mark2[y]) continue;
		Ans[y]=Ans[a]-1;// -1
		calc_ans(y);
	}
}
void enter()
{
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll a,b;cin>>a>>b;
		out[a].PB(b);
		in[b].PB(a);
	}
}
int main()
{
	enter();dfs(1);Ans[1]=dp[1];calc_ans(1);
	ll Min=Ans[1];stack<ll> s;
	for(ll i=n;i>0;i--) 
		if(Min>Ans[i]) {Min=Ans[i];s=stack<ll>();s.push(i);}
		else if(Min==Ans[i]) s.push(i);
	cout<<Min<<endl;
	while(!s.empty()) {cout<<s.top()<<" ";s.pop();}
}