#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	set<ll> in;
	int n; cin >> n;
	vector<ll> v(n);
	vector<ll> ne;
	int ze = 0;
	for(auto &x : v)cin >> x, in.insert(x);
	for(int i = 0; i < n; ++i){
		if(v[i] != 0)ne.push_back(v[i]);
		else ze++;
	}
	if(ne.size() > 10){
		cout << "NO\n";
		return;
	}
	for(int i = 0; i < min(5,ze); ++i)ne.push_back(0);
	int x = ne.size();
	for(int i = 0; i < x; ++i){
		for(int j = i+1; j < x; ++j){
			for(int z = j+1; z < x; ++z){
				if(!in.count(ne[i]+ne[j]+ne[z])){
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}