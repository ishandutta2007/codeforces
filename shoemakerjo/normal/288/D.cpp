#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 80010

int n;
int subsize[maxn];
vector<vector<int>> adj(maxn);
vector<int> eulertree; //flattened version
int st[maxn], en[maxn]; //euler tree numbers
ll seg[maxn*4];
ll ans;
ll onpath = 0LL;
ll measlca[maxn];
ll cp[maxn]; //store the current path modification

//sum for segment tree i think

ll qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	if (qs <= ss && se <= qe) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	return qu(qs, qe, ss, mid, si*2+1) + 
		qu(qs, qe, mid+1, se, si*2+2);
}

ll query(int qs, int qe) {
	return qu(qs, qe, 0, n-1, 0);
}

void up(int spot, ll val, int ss, int se, int si) {
	if (spot > se || spot < ss) return;
	if (ss == se) {
		seg[si] = val;
		return;
	}
	int mid = (ss+se)/2;
	up(spot, val, ss, mid, si*2+1);
	up(spot, val, mid+1, se, si*2+2);
	seg[si] = seg[si*2+1] + seg[si*2+2]; //sum segment tree
}

void update(int spot, ll val) {
	up(spot, val, 0, n-1, 0);
}

void makenormal(int u) {
	ll val = measlca[u];
	update(st[u], val);
}

void modify(int u, int ch) {
	update(st[u], 0LL); //we store these guys separately
	ll above = n - subsize[u]; //guys above me
	ll below = subsize[u] - subsize[ch]; //includes me
	ll remo = (subsize[ch]+0LL)*below; //the mapping of those nerds to us
	ll nval = measlca[u] - remo; //covers the children stuff
	nval += above*below; //it is good to map to me here
	cp[u] = nval;
	onpath += nval;
}

void dfs(int u, int p) {
	//consider u as the lca overall
	ll cv = measlca[u]; //get guys passing through me
	//add the no ancestor ones
	ans += cv*(query(0, st[u]-1) + (query(en[u]+1, n-1))); 
	//above will happen twice so we are good on that front

	// cout << "adding disjoint for: " << u << "    " <<
		// cv*(query(0, st[u]-1) + (query(en[u]+1, n-1))) << endl;

	ans += cv*(onpath)*2LL; //add this twice b/c not counted for other

	// cout << "adding ancestor for: " << u << "   " << cv*(onpath) << endl;

	for (auto v : adj[u]) {
		if (v == p) continue;
		modify(u, v); //do the necessary modification
		dfs(v, u); //walk down the tree
		onpath -= cp[u]; //delete what we added 
	}
	makenormal(u); //restore to normality

}

void predfs(int u, int p) {
	//subsize is done here
	measlca[u] = 0LL;
	subsize[u] = 1;
	st[u] = eulertree.size();
	eulertree.push_back(u);
	for (auto v : adj[u]) {
		if (v == p) continue;
		predfs(v, u);
		measlca[u] += subsize[v]*(subsize[u]+0LL); //how clever (i hope)
		subsize[u] += subsize[v];
	}
	en[u] = eulertree.size()-1; //i like inclusive
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(seg, seg+maxn*4, 0LL);
	predfs(1, -1);
	ans = 0LL;
	onpath = 0LL;
	//must normalize all first
	for (int i = 1; i <= n; i++) {
		makenormal(i);
	}
	dfs(1, -1); //this will be the main guy

	cout << ans << endl;
	cin >> n;
}