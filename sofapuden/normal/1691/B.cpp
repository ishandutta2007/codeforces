#include<bits/stdc++.h>
 
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
	if(a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n ;++i){
		cin >> v[i].first;
		v[i].second = i;
	}
	for(int i = 0; i < n-1; ++i){
		if(v[i].first == v[i+1].first){
			swap(v[i],v[i+1]);
		}
	}
	for(int i = 0; i < n; ++i){
		if(v[i].second == i){
			cout << -1 << '\n';
			return;
		}
	}
	for(int i = 0; i < n; ++i){
		cout << v[i].second+1 << ' ';
	}
	cout << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}