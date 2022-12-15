#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1007;
const int kMaxM = 1007;
const int kMaxK = 41;
const int kMaxQ = 1e5 + 7;
const int kInf = 1e4;

struct my_pair{
	int first;
	bool second;

	my_pair(int first, bool second){
		this->first = first;
		this->second = second;
	}
};

short dist[kMaxK][kMaxK + kMaxN * kMaxM];

vector<my_pair> adj[kMaxK + kMaxN * kMaxN];
bool used[kMaxK + kMaxN * kMaxM];
int n, m, k;
vector<int> q[2 * kMaxN + 2 * kMaxM + kMaxK];

void bfs(int start){
	dist[start][start] = 0;
	q[0].push_back(start);
	
	int cnt = 1;
	for(int d = 0; cnt; ++d){
		for(int u: q[d]){
			--cnt;
			if(used[u])
				continue;
			used[u] = true;

			for(auto edge: adj[u]){
				int to = edge.first;
				bool w = edge.second;
				if(used[to])
					continue;

				if(dist[start][u] + w + 1 < dist[start][to]){
					dist[start][to] = dist[start][u] + w + 1;
					q[dist[start][to]].push_back(to);
					++cnt;
				}
			}
		}
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int color;
			cin >> color;
			--color;
			adj[color].push_back({i * m + j + k, false});
			adj[i * m + j + k].push_back({color, false});
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i != 0)
				adj[i * m + j + k].push_back({(i - 1) * m + j + k, true});
			if(i != n - 1)
				adj[i * m + j + k].push_back({(i + 1) * m + j + k, true});
			if(j != 0)
				adj[i * m + j + k].push_back({i * m + (j - 1) + k, true});
			if(j != m - 1)
				adj[i * m + j + k].push_back({i * m + (j + 1) + k, true});
		}
	}

	for(int i = 0; i < k; ++i){
		for(int j = 0; j < k + n * m; ++j){
			used[j] = false;
			dist[i][j] = kInf;
		}
		for(int j = 0; j < 10 + 2 * n + 2 * m; ++j)
			q[j].clear();
		bfs(i);
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1, --c1, --r2, --c2;

		int ans = abs(r1 - r2) + abs(c1 - c2);
		for(int j = 0; j < k; ++j){
			//cout << j + 1 << " col " << dist[j][r1 * m + c1 + k] + dist[j][r2 * m + c2 + k] << "\n";
			ans = min(ans, (dist[j][r1 * m + c1 + k] + dist[j][r2 * m + c2 + k]) / 2);
		}

		cout << ans << "\n";
	}
}