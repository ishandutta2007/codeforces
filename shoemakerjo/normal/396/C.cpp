#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 300010

const int mod = 1000000007LL;
int n, q;
vector<vector<int>> adj(maxn); //will only store the children
int dep[maxn]; //just the depth of each node in the tree
vector<int> flat; //flattened version of the tree

int seg[2][maxn*4]; //index 0 is for non-scaling, 1 is for scaling
//keep second one positive and then subtract
int lazy[2][maxn*4];
int st[maxn], en[maxn]; //euler tree values

int mult(int a, int b) {
	return (a*1LL*b)%mod;
}

void add(int &a, int b) {
	a = (a+b)%mod;
}

void delaze(int ss, int se, int si) {
	
	add(seg[0][si], lazy[0][si]);
	add(seg[1][si], lazy[1][si]);
	
	if (ss != se) {
		add(lazy[0][si*2+1], lazy[0][si]);
		add(lazy[0][si*2+2], lazy[0][si]);
		add(lazy[1][si*2+1], lazy[1][si]);
		add(lazy[1][si*2+2], lazy[1][si]);
	}
	lazy[0][si] = 0;
	lazy[1][si] = 0; //set to zero

}

void predfs(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	st[u] = flat.size();
	flat.push_back(u);
	for (auto v : adj[u]) {
		predfs(v, u);
	}
	en[u] = flat.size()-1; //inclusive is better
}

void up(int ind, int us, int ue, ll val, int ss, int se, int si) {
	delaze(ss, se, si);
	if (us > se || ue < ss || us > ue || ss > se) return;
	if (us  <= ss && se <= ue) { //completely nested
		add(lazy[ind][si], val);
		delaze(ss, se, si); //why not
		return;
	}
	int mid = (ss+se)/2;
	up(ind, us, ue, val, ss, mid, si*2+1);
	up(ind, us, ue, val, mid+1, se, si*2+2);
	//no need to update this nodes values b/c range queries are never done

}

void update(int ind, int us, int ue, ll val) {
	up(ind, us, ue, val, 0, n-1, 0);
}


pair<int, int> query(int spot, int ss, int se, int si) { 
	//spot is the designated index
	delaze(ss, se, si);
	if (ss == se) {
		return make_pair(seg[0][si], seg[1][si]);
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		return query(spot, ss, mid, si*2+1);
	}
	return query(spot, mid+1, se, si*2+2);
}

int getans(int v) {
	pair<int, int> tempo = query(st[v], 0, n-1, 0);
	// cout << "two vals for " << v << " were  " << 
	// 	tempo.first << " " << tempo.second << endl;
	int fi = tempo.first;
	int su = mult(tempo.second, dep[v]);
	int ans = (fi+mod-su)%mod; //make sure it is all positive
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int p;
	for (int  i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i); //only store my children in my adj list
	}

	fill(seg[0], seg[0]+maxn*4, 0);
	fill(seg[1], seg[1]+maxn*4, 0);
	fill(lazy[0], lazy[0]+maxn*4, 0);
	fill(lazy[1], lazy[1]+maxn*4, 0);

	predfs(1, -1);
	assert(flat.size() == n);
	cin >> q;
	int tp, v;
	ll x, k; //values from the statements
	while (q--) {
		cin >> tp;
		if (tp == 1) {
			cin >> v >> x >> k;
			int offset = mult(k, dep[v]);
			add(offset, x); //add the whole thing the offset plus x
			update(0, st[v], en[v], offset); //add this to offset subbing
			update(1, st[v], en[v], k); //add k to the multiplier part
		}
		else { //tp is 2
			cin >> v;
			cout << getans(v) << '\n';
		}
	}
	cin >> tp;

}
//need to somehow speed this up (it is fast enough algorithmically but is having issues)
//suggestion: try to speed up the delaze function (e.g. only do stuff if nonzero maybe)
//suggestion: use ints instead of long longs (should be 2x speed0)