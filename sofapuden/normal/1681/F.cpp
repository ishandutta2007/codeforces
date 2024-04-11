#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<map<int,pair<ll,ll>>> v;
vector<ll> sz;
vector<vector<pair<ll,ll>>> tr;

ll ans = 0;

ll fil(int x, int p){
	sz[x] = 1;
	for(auto y : tr[x])if(y.first != p)sz[x]+=fil(y.first,x);
	return sz[x];
}

void f(int x, int p, int pat){
	for(auto y : tr[x]){
		if(y.first != p){
			f(y.first,x,y.second);
			if(v[x].size() < v[y.first].size()){
				swap(v[x],v[y.first]);
			}
			for(auto z : v[y.first]){
				v[x][z.first].first += z.second.first;
				v[x][z.first].second += z.second.second;
			}
		}
	}
	if(pat){
		ans+=v[x][pat].first * (sz[x]-v[x][pat].second);
		v[x][pat].first = sz[x]-v[x][pat].second;
		v[x][pat].second = sz[x];
	}
}

void solve(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;cin >> n;
	v.resize(n);
	sz.resize(n);
	tr.resize(n);
	for(int i =0 ; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		int c; cin >> c;
		tr[a].push_back({b,c});
		tr[b].push_back({a,c});
	}
	fil(0,0);
	f(0,0,0);
	for(auto x : v[0]){
		ans+=x.second.first*(n-x.second.second);
	}
	cout << ans << '\n';
}

int main(){
	solve();

}