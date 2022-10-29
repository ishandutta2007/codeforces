#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9+7;

set<int> S;

bool cmp(int a, int b){
	if(!S.count(b) && !S.count(a))return a < b;
	return S.count(b);
}

void solve(){
	S.clear();
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<vector<int>> z(n+2);
	int bd = 0;
	for(int i = 0; i < n; ++i){
		S.insert(v[i]);
		z[v[i]].push_back(i+1);
		if(i < v[i])bd++;
	}
	for(int i = 0; i < n+2; ++i){
		sort(z[i].begin(),z[i].end(),cmp);
	}
	cout << bd << '\n';
	if(z[0].size()){
		int cu = 0;
		while(z[cu].size()){
			for(auto x : z[cu])cout << x << ' ';
			cu = z[cu].back();
		}
	}
	else{
		int cu = n+1;
		while(z[cu].size()){
			for(auto x : z[cu])cout << x << ' ';
			cu = z[cu].back();
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}