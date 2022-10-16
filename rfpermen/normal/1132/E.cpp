#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n; i<=N; i++)

ll x,cnt[9];
map<ll,ll> dp[9];

ll f(int id,ll rem){
	if(!id)return 0;
	if(dp[id].find(rem)!=dp[id].end())return dp[id][rem];
	ll ret = 0, z = min(cnt[id],rem/id);
	rep(i,max(0ll,z-10),z)ret = max(ret,i*id+f(id-1,rem-i*id));
	return dp[id][rem] = ret;
}

int main(){
	cin>>x;
	rep(i,1,8)cin>>cnt[i];
	cout<<f(8,x)<<endl;
	return 0;
}