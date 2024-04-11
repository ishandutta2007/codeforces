#include<bits/stdc++.h>

using namespace std;

void dfs(int x, int p, vector<int> &a, vector<int> &b, vector<vector<int>> &gr){
	a.push_back(x);
	for(auto y : gr[x])if(y != p)dfs(y,x,b,a,gr);
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> gr(n);
	vector<int> col1, col2;
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(0,0,col1,col2,gr);
	vector<int> ou(n);
	if(col1.size() < col2.size()){
		swap(col1,col2); 
	}
	int k = n - (1 << (int)(log2(n)));
	n = (int)(log2(n));
	for(int i = 0; i <= k; ++i){
		ou[col1.back()] = (1<<n)+i;
		col1.pop_back();
	}
	for(int i = 0; i < n; ++i){
		if((int)col1.size() & (1<<i)){
			for(int j = 0; j < (1<<i); ++j){
				ou[col1.back()] = (1<<i)+j;
				col1.pop_back();
			}
		}
		else{
			for(int j = 0; j < (1<<i); ++j){
				ou[col2.back()] = (1<<i)+j;
				col2.pop_back();
			}
		}
	}
	for(auto x : ou)cout << x << ' ';
	cout << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}