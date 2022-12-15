#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 2e5 + 7;
const int inf = 1e9;

vector<int> adj[kMaxN];
int a[kMaxN], dist_1[kMaxN], dist_n[kMaxN];
bool used[kMaxN];
pair<int, int> dc_1[kMaxN], dc_n[kMaxN];
int n, m, k;

void bfs(int start, int dist[]){
	queue<int> q;

	q.push(start);
	dist[start] = 0;
	used[start] = true;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int to: adj[u]){
			if(used[to])
				continue;

			used[to] = true;
			q.push(to);
			dist[to] = dist[u] + 1;
		}
	}
}

bool check(int mid){
	set<pair<int, int>> possible;

	int j = k - 1;
	for(int i = 0; i < k; ++i){
		while(j >= 0 && dc_n[j].first + dc_1[i].first + 1 >= mid){
			possible.insert( {dist_1[ dc_n[j].second ], dc_n[j].second} );
			--j;
		}
		if(possible.count( {dist_1[ dc_1[i].second ], dc_1[i].second} )){
			possible.erase( {dist_1[ dc_1[i].second ], dc_1[i].second} );
			if(!possible.empty() && possible.rbegin()->first + dist_n[dc_1[i].second] >= mid)
				return true;
			possible.insert( {dist_1[ dc_1[i].second ], dc_1[i].second} );
		}
		else{
			if(!possible.empty() && possible.rbegin()->first + dist_n[dc_1[i].second] >= mid)
				return true;
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 0; i < k; ++i)
		cin >> a[i];

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1, dist_1);
	for(int i = 1; i <= n; ++i)
		used[i] = false;
	bfs(n, dist_n);

	int before = dist_1[n];

	for(int i = 0; i < k; ++i)
		dc_1[i] = {dist_1[a[i]], a[i]};
	sort(dc_1, dc_1 + k);

	for(int i = 0; i < k; ++i)
		dc_n[i] = {dist_n[a[i]], a[i]};
	sort(dc_n, dc_n + k);

	int l = 1, r = inf;
	while(l != r){
		int mid = (l + r + 1) >> 1;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}

	cout << min(l, before) << "\n";
}