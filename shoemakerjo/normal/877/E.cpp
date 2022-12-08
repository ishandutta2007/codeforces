#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
int n;
vector<int> nlist;
vector<vector<int>> child;
int par[maxn];
int state[maxn];
int bc[maxn];
int ec[maxn];
int lazy[maxn*4];
int sums[maxn*4];
int ups[maxn*4];

void dfs(int u) {
	bc[u] = nlist.size();
	nlist.push_back(u);
	for (int i = 0; i < child[u].size(); i++) {
		int v = child[u][i];
		dfs(v);
	}
	ec[u] = nlist.size()-1;
}

int qu(int qs, int qe, int ss, int se, int si) {
	if (lazy[si] != 0) {
		if (lazy[si]%2==1) {
			sums[si] = (se-ss+1)-sums[si];
		}
		if (ss != se) {
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (qs > qe || qs > se || qe < ss) return 0;
	if (qs <= ss && se <= qe) {
		return sums[si];
	}
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) + qu(qs, qe, mid+1, se, si*2+2);
}

int query(int spot) {
	return qu(bc[spot], ec[spot], 0, n-1, 0);
}

void up(int us, int ue, int ss, int se, int si) {
	if (lazy[si] != 0) {
		if (lazy[si]%2==1) {
			sums[si] = (se-ss+1)-sums[si];
		}
		if (ss != se) {
			lazy[si*2+1] += lazy[si];
			lazy[si*2+2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (us > ue || us > se || ue < ss) return;
	if (us <= ss && se <= ue) {
		sums[si] = (se-ss+1)-sums[si];
		if (ss != se) {
			lazy[si*2+1]++;
			lazy[si*2+2]++;
		}
		return;
	}
	int mid = (ss+se)/2;
	up(us, ue, ss, mid, si*2+1);
	up(us, ue, mid+1, se, si*2+2);
	sums[si] = sums[si*2+1] + sums[si*2+2];
}

void update(int spot) {
	up(bc[spot], ec[spot], 0, n-1, 0);
}

void buildtree(int ss, int se, int si) {
	if (ss == se) {
		sums[si] = state[nlist[ss]];
		return;
	}
	int mid = (ss+se)/2;
	buildtree(ss, mid, si*2+1);
	buildtree(mid+1, se, si*2+2);
	sums[si] = sums[si*2+1] + sums[si*2+2];
}

int main() {
	for (int i = 0; i < maxn*4; i++) lazy[i] = sums[i] = ups[i] = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		child.push_back(b);
	}
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		child[par[i]].push_back(i);
	}
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> state[i];
	}
	dfs(1);
	buildtree(0, n-1, 0);

	//handle queries
	int q;
	cin >> q;
	string type;
	int spot;
	for (int i = 0; i < q; i++) {
		cin >> type >> spot;
		if (type == "get") {
			cout << query(spot) << '\n';
		}
		else {
			update(spot);
		}
	}
	cin >> q;
}