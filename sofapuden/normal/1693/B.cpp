#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int dfs(int x, vector<vector<int>> &gr, vector<pair<ll,ll>> &tar, vector<ll> &val){
	ll su = 0;
	int ret = 0;
	for(auto y : gr[x]){ret+=dfs(y,gr,tar,val);su += val[y];}
	su = min(su,tar[x].second);
	if(su < tar[x].first){su = tar[x].second;ret++;}
	val[x] = su;
	return ret;
}
 
void solve(){
	int n; cin >> n;
	vector<int> p(n);
	for(int i = 1; i < n; ++i)cin >> p[i];
	vector<pair<ll,ll>> tar(n);
	vector<ll> val(n);
	vector<vector<int>> gr(n);
	for(int i = 1; i < n; ++i){
		gr[p[i]-1].push_back(i);
	}
	for(auto &x : tar)cin >> x.first >> x.second;
	cout << dfs(0,gr,tar,val) << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}