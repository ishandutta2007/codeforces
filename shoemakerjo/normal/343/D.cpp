#include <bits/stdc++.h>
#define maxn 500001
using namespace std;
int n;
int start[maxn], endings[maxn];
vector<vector<int>> adj;
vector<int> nums;
int seg[maxn*4];
int seg2[maxn*4];
int lazy[maxn*4];

void dfs(int u, int p) {
	start[u]  = nums.size()+1;
	nums.push_back(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
	endings[u] = nums.size();
}

void ufill(int us, int ue, int ss, int se, int si, int val) {
	seg[si] = max(seg[si], lazy[si]);
	if (ss != se) {
		lazy[si*2+1] = max(lazy[si*2+1], lazy[si]);
		lazy[si*2+2] = max(lazy[si*2+2], lazy[si]);
	}

	if (us > se || ss > se || ue < ss) {
		return;
	}
	if (us <= ss && se <= ue) {
		seg[si] = max(seg[si], val);
		if (ss != se) {
			lazy[si*2+1] = max(lazy[si*2+1], val);
			lazy[si*2+2] = max(lazy[si*2+2], val);
		}
		return;
	}
	int mid = (ss+se)/2;
	ufill(us, ue, ss, mid, si*2+1, val);
	ufill(us, ue, mid+1, se, si*2+2, val);
	seg[si] = max(seg[si*2+1], seg[si*2+2]);
}
void updatefill(int spot, int val) {
	ufill(start[spot], endings[spot], 1, n, 0, val);
}

int qufill(int qs, int qe, int ss, int se, int si) {
	seg[si] = max(seg[si], lazy[si]);
	if (ss != se) {
		lazy[si*2+1] = max(lazy[si*2+1], lazy[si]);
		lazy[si*2+2] = max(lazy[si*2+2], lazy[si]);
	}
	if (ss > se || qs > qe || qe < ss || qs > se) {
		return 0;
	}
	if (qs <= ss && se <= qe) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return max(qufill(qs, qe, ss, mid, si*2+1),
			qufill(qs, qe, mid+1, se, si*2+2));
}

int queryfill(int spot) {
	return qufill(start[spot], start[spot], 1, n, 0);
}

void upempty(int spot, int ss, int se, int si, int val) {
	if (ss > se || spot < ss || spot > se) return;
	if (ss == se) {
		seg2[si] = max(seg2[si], val);
		return;
	}
	int mid= (ss+se)/2;
	upempty(spot, ss, mid, si*2+1, val);
	upempty(spot, mid+1, se, si*2+2, val);
	seg2[si] = max(seg2[si*2+1], seg2[si*2+2]);
}

int updateempty(int spot, int val) {
	upempty(start[spot], 1, n, 0, val);
}

int quempty(int qs, int qe, int ss, int se, int si) {
	if (ss > se || qe < ss || qs > se) {
		return 0;
	}
	if (qs <= ss && se <= qe) {
		return seg2[si];
	}
	int mid = (ss+se)/2;
	return max(quempty(qs, qe, ss, mid, si*2+1),
			quempty(qs, qe, mid+1, se, si*2+2));
}

int queryempty(int spot) {
	return quempty(start[spot], endings[spot], 1, n, 0);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int q; cin >> q;
	int c, v;
	dfs(1, 0);
	for (int i = 0; i < maxn*4; i++) {
		seg[i] = lazy[i] = seg2[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		// cout << "start  " << start[i] << " " << endings[i] << endl;
	}
	for (int i = 1; i <= q; i++) {
		cin >> c >> v;
		if (c == 1) {
			updatefill(v, i);
		}
		if (c == 2) {
			updateempty(v, i);
		}
		if (c == 3) {
			int ftime = queryfill(v);
			int etime = queryempty(v);
			// cout << "times:  " << ftime << " " << etime << endl;
			// cout << "ans:  ";
			if (ftime > etime) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}
	// cin >> a;
	


}