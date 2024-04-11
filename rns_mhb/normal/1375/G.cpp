#include<bits/stdc++.h>
using namespace std;

#define N 200010

vector <int> adj[N];
int d[N];

void dfs(int x, int p) {
	for(auto y : adj[x]) {
		if(y == p) continue;
		d[y] = d[x] ^ 1;
        dfs(y, x);
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1, x, y; i < n; i ++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	int x = 0, y = 0;
	for(int i = 1; i <= n; i ++) {
		if(d[i]) x ++;
		else y ++;
	}
	cout << min(x, y)-1 << endl;
}