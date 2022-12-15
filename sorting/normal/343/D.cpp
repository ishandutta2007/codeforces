#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

struct segment_tree{
	bool arr[8 * MAXN];
	int n;

	segment_tree(){}

	void init(int idx, int l, int r){
		if(l == r){
			arr[idx] = true;
			return;
		}

		int mid = (l + r) >> 1;

		init(2 * idx, l, mid);
		init(2 * idx + 1, mid + 1, r);

		arr[idx] = arr[2 * idx] || arr[2 * idx + 1];
	}

	void init_tree(int n){
		this -> n = n;
		init(1, 0, n - 1);
	}

	void update_in(int idx, int l, int r, int sl, int sr, bool val){
		if(l > sr || r < sl){
			return;
		}
		if(sl <= l && r <= sr){
			arr[idx] = val;
			return;
		}

		if(!arr[idx]){
			arr[2 * idx] = false;
			arr[2 * idx + 1] = false;
		}

		int mid = (l + r) >> 1;
		update_in(2 * idx, l, mid, sl, sr, val);
		update_in(2 * idx + 1, mid + 1, r, sl, sr, val);

		arr[idx] = arr[2 * idx] || arr[2 * idx + 1];
	}

	void update(int l, int r, bool val){
		update_in(1, 0, n - 1, l, r, val);
	}

	bool query_in(int idx, int l, int r, int sl, int sr){
		if(l > sr || r < sl){
			return false;
		}
		if(sl <= l && r <= sr){
			return arr[idx];
		}

		if(!arr[idx]){
			arr[2 * idx] = false;
			arr[2 * idx + 1] = false;
		}

		int mid = (l + r) >> 1;

		bool lvalue = query_in(2 * idx, l, mid, sl, sr);
		bool rvalue = query_in(2 * idx + 1, mid + 1, r, sl, sr);

		return (lvalue || rvalue);
	}

	bool query(int l, int r){
		return query_in(1, 0, n - 1, l, r);
	}
};

segment_tree st;

int n, q, m;
vector<int> adj[MAXN], e;
int tin[MAXN], tout[MAXN], par[MAXN];

void dfs(int u, int p = -1){
	e.push_back(u);
	tin[u] = (int)e.size() - 1;
	par[u] = p;

	for(int to: adj[u]){
		if(to == p){
			continue;
		}

		dfs(to, u);
		e.push_back(u);
	}
	tout[u] = (int)e.size() - 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n - 1; ++i){
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	st.init_tree(e.size());

	cin >> q;

	for(int i = 0; i < q; ++i){
		int type, v;

		cin >> type >> v;

		if(type == 1){
			//fill
			bool tmp = st.query(tin[v], tout[v]);

			st.update(tin[v], tout[v], 0);
			if(tmp){
				if(par[v] == -1){
					continue;
				}
				st.update(tin[par[v]], tin[par[v]], 1);
			}
			continue;
		}
		if(type == 2){
			//erase

			st.update(tin[v], tin[v], 1);
			continue;
		}
		if(type == 3){
			//output
			cout << (st.query(tin[v], tout[v]) ? 0 : 1) << "\n";
			continue;
		}
	}

	return 0;
}