#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> dp;

set<int> finlis(vector<int> v){
	dp.clear();
	int n = v.size();
	vector<int> p(n);
	set<int> ret;
	dp.push_back({0});
	p[0] = -1;
	for(int i = 1; i < n; ++i){
		int l = 0, r = dp.size()-1, bes = -1;
		while(l <= r){
			int m = (l+r)>>1;
			if(v[dp[m].back()] > v[i]){
				r = m-1;
			}
			else{
				l = m+1;
				bes = m;
			}
		}
		if(bes == dp.size()-1){
			dp.push_back({i});
			p[i] = (bes == -1 ? -1 : dp[bes].back());
		}
		else{
			dp[bes+1].push_back(i);
			p[i] = (bes == -1 ? -1 : dp[bes].back());
		}
	}
	int x = dp.back().back();
	while(x != -1){
		ret.insert(x);
		x = p[x];
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		vector<vector<int>> ou;
		while(v.size()){
			ou.push_back({});
			n = v.size();
			ll l = 1, r = n, k = 0;
			while(l <= r){
				ll m = (l+r)>>1;
				if((m*(m+1))/2 <= n){
					k = m;
					l = m+1;
				}
				else{
					r = m - 1;
				}

			}
			set<int> lis = finlis(v);
			if(lis.size() > k){
				vector<int> ne;
				for(auto x : lis){
					ou.back().push_back(v[x]);
				}
				for(int i = 0; i < n; ++i){
					if(lis.count(i))continue;
					ne.push_back(v[i]);
				}
				v = ne;
			}
			else{
				ou.pop_back();
				for(auto x : dp){
					ou.push_back({});
					for(auto y : x){
						ou.back().push_back(v[y]);
					}
				}
				v.clear();
			}
		}
		cout << ou.size() << '\n';
		for(auto x : ou){
			cout << x.size() << ' ';
			for(auto y : x)cout << y << ' ';
			cout << '\n';
		}
	}
}