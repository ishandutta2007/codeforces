//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
const int Maxn = 1e6 + 9;
ll dp[Maxn],ans[Maxn];
vector<int> al[Maxn];
ll pw(ll a,ll b){
	return b?(pw((a * a) % Mod,b >> 1) * (b & 1?a:1))%Mod:1;
}
ll inv(ll a){
	return pw(a,Mod-2);
}
ll dfs_dp(ll v,ll p = -1){
	if(dp[v] != -1) return dp[v];
	ll res = 1;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i];
		if(u == p) continue;
		res *= (dfs_dp(u,v) + 1);
		res %= Mod;
	}
	return dp[v] = res;
}
ll dfs_ans(ll v,ll p = -1,ll cur = 1){
	ll res = 1;
	vector<ll> ls,rs;
	ls.clear(),rs.clear();
	ls.push_back(1);
	rs.push_back(1);
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i];
		if(u == p) continue;
		res *= (dfs_dp(u,v) + 1);
		res %= Mod;
		ls.push_back(res);
	}
	res = 1;
	for(int i = al[v].size()-1;i + 1;--i){
		int u = al[v][i];
		if(u == p) continue;
		res *= (dfs_dp(u,v) + 1);
		res %= Mod;
		rs.push_back(res);
	}
	int l = 0,r = rs.size() - 2;
	ans[v] = (res * cur) % Mod;
	//if(p + 1) ans[v] += res,ans[v] %= Mod;
	for(int i = 0; i < al[v].size();i++){
		int u = al[v][i];
		if(u == p) continue;
 		dfs_ans(u,v,((((cur) * ((rs[r] * ls[l])%Mod)) % Mod)+1) % Mod);
		l++,r--;
	}
	return 0;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1;i++){
		int p;
		scanf("%d",&p);
		p--;
		al[p].push_back(i+1);
		al[i+1].push_back(p);
	}
	memset(dp,-1,sizeof dp);
	dfs_dp(0);
	dfs_ans(0);
	for(int i = 0; i < n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}