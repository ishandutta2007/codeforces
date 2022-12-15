#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

unordered_map<int, bool> adj[N];
vector<vector<int> > res;

bool used[N];

int st[N], where[N];
int cnt;

struct graph{
public:
	graph(int n = 0){
		cnt = n;
		for(int i = 1; i <= n; i++){
			st[i] = i;
			where[i] = i;
		}
	}

	inline int size(){
		return cnt;
	}

	inline int get_node(int ind){
		return st[ind];
	}

	void erase(int x){
		int l = where[x], r = cnt;

		swap(where[ st[l] ],  where[ st[r] ]);
		swap(st[l], st[r]);

		cnt--;
	}
};

graph g;

void dfs(int u){
	stack<int> q;
	q.push(u);
	res.back().push_back(u);

	g.erase(u);
	used[u] = true;

	while(!q.empty()){
		u = q.top();
		q.pop();

		for(int i = 1; i <= g.size(); i++){
			int to = g.get_node(i);

			if(!used[to] && !adj[u][to]){
				used[to] = true;
				res.back().push_back(to);
				g.erase(to);
				q.push(to);
				i--;
			}
		}
	}
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;

	cin >> n >> m;

	g = graph(n);

	for(int i = 0; i < m; i++){
		int x, y;

		cin >> x >> y;

		adj[x][y] = true;
		adj[y][x] = true;
	}

	vector<int> e;

	for(int i = 1; i <= n; i++){
		if(!used[i]){
			res.push_back(e);
			dfs(i);
		}
	}

	cout << res.size() << "\n";

	for(int i = 0; i < res.size(); i++){
		cout << res[i].size() << " ";

		for(int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}