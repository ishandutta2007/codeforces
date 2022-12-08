#include <bits/stdc++.h>
#define maxn 200001
using namespace std;

int seg[maxn*4];
int lazy[maxn*4];
int par[maxn];
int start[maxn];
int endings[maxn];
int depth[maxn];
int vals[maxn]; //add this initial to things
vector<int> nums;

int n, m;
vector<vector<int>> adj;

void dfs(int u, int cpar) {
	start[u] = nums.size();
	nums.push_back(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == cpar) continue;
		par[v] = u;
		depth[v] = depth[u]+1;
		dfs(v, u);
	}
	endings[u] = nums.size()-1;
}

void up(int us, int ue, int ss, int se, int si, int val) {
	// cout << ss << " " << se << " " << si << endl;
	if (lazy[si] != 0) {
		if (ss == se) {
			if (depth[nums[ss]]%2==1) {
				seg[si] -=lazy[si];
			}
			else {
				seg[si] += lazy[si];
			}
		}
		else {
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss > se || us > se || ue < ss) {
		return;
	}
	if (ss == se) {
		if (depth[nums[ss]]%2==1) {
			seg[si] -= val;
		}
		else seg[si]+= val;
		return;
	}
	if (us <= ss && se <= ue) {
		lazy[si*2+1]+=val;
		lazy[si*2+2]+=val;
		return;
	}
	int mid = (ss+se)/2;
	up(us, ue, ss, mid, si*2+1, val);
	up(us, ue, mid+1, se, si*2+2, val);
}

void update(int num, int val) {
	// cout << "num:  " << num << " " << val << endl;
	if (depth[num]%2==1) {
		up(start[num], endings[num], 0, n-1, 0, 0-val);
	}
	else {
		up(start[num], endings[num], 0, n-1, 0, val);
	}
}

int qu(int qs, int qe, int ss, int se, int si) {
	if (lazy[si] != 0) {
		if (ss == se) {
			if (depth[nums[ss]]%2==1) {
				seg[si] -=lazy[si];
			}
			else {
				seg[si] += lazy[si];
			}
		}
		else {
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss > se || ss > qe || se < qs) {
		return 0;
	}
	if (ss == se) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) +
		qu(qs, qe, mid+1, se, si*2+2);
}

int query(int num) {
	return qu(start[num], start[num], 0, n-1, 0) + vals[num];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i  < maxn*4; i++) {
		seg[i] = lazy[i] = 0;
	}
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	int u, v;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[1] = 0;
	dfs(1, -1);
	// cout << "here" << endl;
	int type, x, val;
	for (int i = 0; i < m; i++) {
		cin >> type >> x;
		if (type == 1) {
			cin >> val;
			update(x, val);
		}
		else {
			int ans = query(x);
			// cout << "ans: " << ans << endl;
			cout << ans << '\n';
		}
	}
	// cin >> n;

}