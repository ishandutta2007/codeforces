#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

vector<int> v;
vector<vector<int>> gr;
void dfs(int x){
	for(auto y : gr[x])dfs(y);
	for(auto y : gr[x])v[x]+=v[y];
}

void solve(){
	int n; cin >> n;
	v.clear();
	v.resize(n,0);
	gr.clear();
	gr.resize(n);
	for(int i = 1; i < n; ++i){
		int x; cin >> x;
		x--;
		gr[x].push_back(i);
	}
	string s; cin >> s;
	for(int i = 0; i < n; ++i){
		v[i] = (s[i] == 'B' ? 1 : -1);
	}
	dfs(0);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += !v[i];
	}
	cout << ans << '\n';
}

int main(){

	int t; cin >> t;
	while(t--)solve();

}