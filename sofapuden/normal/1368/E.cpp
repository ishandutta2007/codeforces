#include<bits/stdc++.h>
 
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<int>> gr(n);
	for(int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		gr[a].push_back(b);
	}
	for(int i = 0; i < n; ++i)sort(gr[i].begin(),gr[i].end());
	vector<int> vis(n,0);
	int k = 0;
	for(int i = 0; i < n; ++i){
		if(!vis[i]){
			vis[i] = 1;
			for(auto y : gr[i]){
				if(!vis[y])vis[y] = 1;
			}
		}
		else if(vis[i] == 1){
			for(auto y : gr[i]){
				vis[y] = 2;
			}
		}
		k+=vis[i]&2;
	}
	assert(k/2 <= (4*n)/7);
	cout << k/2 << '\n';
	for(int i = 0; i < n; ++i){
		if(vis[i]&2){
			cout << i+1 << ' ';
		}
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}