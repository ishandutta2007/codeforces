#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	map<int,vector<int>> M;
	for(int i = 0; i < n; ++i){
		M[v[i]].push_back(i);
	}
	int ans = 0;
	int num = -1, l = -1, r = -1;
	for(auto x : M){
		int su = -1;
		int ls = -1;
		int st = 0;
		for(auto y : x.second){
			su-=y-ls-1;
			if(su < 0){
				su = 0;
				st = y;
			}
			su++;
			if(su > ans){
				ans = su;
				l = st, r = y, num = x.first;
			}
			ls = y;
		}
	}
	cout << num << ' ' << l+1 << ' ' << r+1 << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}