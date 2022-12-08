#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 100010

ll parlen[maxn];
ll pathlen[3][maxn]; //three best for each node
int pathid[3][maxn]; //store the name of the guy
vector<int> eulertree; //flattened tree stored here
int st[maxn]; //these two store euler flattening numbers
int en[maxn]; //this will be inclusive (i like it better)
ll seg[maxn*4]; //segment tree - pretty standard
vector<vector<int>> adj(maxn); //standard adjacency list
int n;
ll nums[maxn];
ll ans;

ll qu(int qs, int qe, int ss, int se, int si) {
	if (qs > qe || ss > se || qs > se || qe < ss) return 0LL;
	if (qs <= ss && se <= qe) return seg[si];
	int mid = (ss+se)/2;
	return max(qu(qs, qe, ss, mid, si*2+1),
		qu(qs, qe, mid+1, se, si*2+2));
}


ll query(int qs, int qe) {
	return qu(qs, qe, 0, n-1, 0);
}

void up(int spot, ll val, int ss, int se, int si) {
	if (spot > se || spot < ss || ss > se) return;
	if (spot == ss && spot == se) {
		seg[si] = val;
		return;
	}
	int mid = (ss+se)/2;
	up(spot, val, ss, mid, si*2+1); //we don't have to do both (speed up)
	up(spot, val, mid+1, se, si*2+2);
	seg[si] = max(seg[si*2+1], seg[si*2+2]); //RMQ update
}

void update(int spot, ll val) { //update segment tree value
	up(spot, val, 0, n-1, 0); //euler tree is zero indexed
}

void modify(int u, int ch) { //modify such that the path to ch is out
	ll b2 = 0LL; //take 2 best children not equal to ch
	if (pathid[0][u] == ch) {
		b2 = pathlen[1][u] + pathlen[2][u] + nums[u];
	}
	else if (pathid[1][u] == ch) {
		b2 = pathlen[0][u] + pathlen[2][u] + nums[u];
	}
	else {
		b2 = pathlen[0][u] + pathlen[1][u] + nums[u];
	}
	ll sec = nums[u] + parlen[u]; //go to parent
	if (pathid[0][u] == ch) {
		sec += pathlen[1][u];
	}
	else {
		sec += pathlen[0][u];
	}
	update(st[u], max(b2, sec));
}

ll getchstuff(int u) {
	ll tsum = pathlen[0][u] + pathlen[1][u] + nums[u];
	return tsum;
}

void makenormal(int u) { //change his value to the normal one
	ll tsum = getchstuff(u);
	update(st[u], tsum); //put this value in its place
}

void predfs(int u, int p) {
	st[u] = eulertree.size();
	eulertree.push_back(u);
	for (auto v : adj[u]) {
		if (v == p) continue;
		predfs(v, u);
	}
	en[u] = eulertree.size()-1;

}

void getch(int u, int p) { //gets child lengths
	for (int i = 0; i < 3; i++) {
		pathid[i][u] = 0; //fill with zeros so no harm done if you add them
		pathlen[i][u] = 0;
	}
	for (auto v : adj[u]) {
		if (v == p) continue;
		getch(v, u);
		ll cv = pathlen[0][v] + nums[v]; //best if we walk to v
		if (cv > pathlen[0][u]) { //flow down twice (yay)
			pathlen[2][u] = pathlen[1][u];
			pathid[2][u] = pathid[1][u];
			pathlen[1][u] = pathlen[0][u];
			pathid[1][u] = pathid[0][u];
			pathlen[0][u] = cv;
			pathid[0][u] = v;
		}
		else if (cv > pathlen[1][u]) { //go down the lines
			pathlen[2][u] = pathlen[1][u];
			pathid[2][u] = pathid[1][u];
			pathlen[1][u] = cv;
			pathid[1][u] = v;
		}
		else if (cv > pathlen[2][u]) { //go down the lines
			pathlen[2][u] = cv;
			pathid[2][u] = v;
		}
	}
}

void getpar(int u, int p) {
	parlen[u] = 0LL;
	if (p != -1) {
		ll op1 = parlen[p] + nums[p];
		ll op2 = nums[p]; //go to child of parent that is not me
		if (pathid[0][p] == u) {
			op2 += pathlen[1][p];
		}
		else op2 += pathlen[0][p];
		parlen[u] = max(op1, op2); 
	}
	for (auto v : adj[u]) {
		if (v == p) continue;
		getpar(v, u);
	}
}

void dfsans(int u, int p) {
	//process u then do stuff for its children then normalize it
	ll outside = max(query(0, st[u]-1), query(en[u]+1, n-1)); //query past me
	ll myans = getchstuff(u) + outside; //should be best for both
	ans = max(ans, myans);

	for (auto v : adj[u]) {
		if (v == p) continue;
		modify(u, v); //do the necessary modification
		dfsans(v, u); //now walk down this side
	}

	makenormal(u); //when we are done with him, normalize him
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	fill(seg, seg+maxn*4, 0LL);

	predfs(1, -1);
	getch(1, -1);
	getpar(1, -1);
	ans = 0LL;
	for (int i = 1; i <= n; i++) {
		makenormal(i); //make sure everything is set to normal before we start
	}
	ans = max(ans, query(0, n-1));
	dfsans(1, -1);
	cout << ans << endl;
	cin >> n;
}