#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	vector<pair<int,int>> v2(n);
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		v[i] = {x,i};
	}
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		v2[i] = {x,i};
	}
	vector<pair<int,int>> out;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n-1; ++j){
			if(v[j].first > v[j+1].first){
				out.emplace_back(j+1,j+2);
				swap(v[j],v[j+1]);
				swap(v2[j],v2[j+1]);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n-1; ++j){
			if(v2[j].first > v2[j+1].first){
				out.emplace_back(j+1,j+2);
				swap(v[j],v[j+1]);
				swap(v2[j],v2[j+1]);
			}
		}
	}
	for(int j = 0; j < n-1; ++j){
		if(v2[j].first > v2[j+1].first || v[j].first > v[j+1].first){
			cout << -1 << '\n';
			return;
		}
	}
	cout << out.size() << '\n';
	for(auto x : out){
		cout << x.first << ' ' << x.second << '\n';

	}

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}