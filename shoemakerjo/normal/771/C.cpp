#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define ll long long

int subSize[maxn];
bool marked[maxn];
int pars[maxn];
vector<vector<int>> adj(maxn);
int n, k;
ll lensum[5]; //store for each mod the count and the length 
ll ctmod[5]; 
ll ans = 0LL;
vector<int> dinserts;

void dfscalc(int u, int p, int dist) {
	int cm = dist%k;
	dinserts.push_back(dist);
	for (int i = 0; i < k; i++) { //figure out how to add to ans
		ll tdist = lensum[i] + ctmod[i]*dist;
		int nm = (i+cm)%k; //new mod
		if (nm != 0) {
			tdist += (ctmod[i]+0LL)*(k-nm); //offset for ceiling maths
		}
		// cout << "	tdist  " << tdist << "  for  " << u << endl;
		assert(tdist%k == 0);
		ans += tdist/(k);
	}
	for (auto v : adj[u]) {
		if (marked[v] || v == p) continue;
		dfscalc(v, u, dist+1);
	}

}	

void calc(int u) {
	for (int i = 0; i < k; i++) { //set everything to zero
		ctmod[i] = 0LL;
		lensum[i] = 0LL;
	}
	ctmod[0] = 1LL; //0 length for the root
	for (auto v : adj[u]) {
		if (marked[v]) continue;
		dinserts.clear();
		dfscalc(v, u, 1);
		//insert them after we calculate for them
		for (int i = 0; i < dinserts.size(); i++) {
			int cd = dinserts[i];
			// cout << "	adding   " << cd << endl;
			lensum[cd%k] += cd + 0LL;
			ctmod[cd%k] += 1LL;
		}
	}

}


//below three methods  implement centroid decomposition nicely
void dfs(int u, int p) {
	pars[u] = p;
	subSize[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (marked[v] || v == p) continue;
		dfs(v, u);
		subSize[u] += subSize[v];
	}
}

int getCentroid(int src, int cSize) {
	int cen = src;
	dfs(cen, -1);
	bool isok = false;
	while (!isok) {
		isok = true;
		for (int i = 0; i < adj[cen].size(); i++) {
			int v = adj[cen][i];
			if (v == pars[cen] || marked[v]) continue;
			if (subSize[v] > cSize/2) {
				isok = false;
				cen = v;
				break;
			}
		}
		// cout << "cenTR   " << cen << endl;
	}
	// cout << "cen    " << cen << endl;
	return cen;
}

void go(int src, int cSize) {
	// cout << "src   " << src << endl;
	int cen = getCentroid(src, cSize);
	marked[cen] = true;
	calc(cen);
	// cout << "current centroid  " << cen << "  " << ans << endl;
	int totseen = 1;
	int after = -1;
	for (int i = 0; i < adj[cen].size(); i++) {
		int v = adj[cen][i];
		if (marked[v]) continue;
		if (v == pars[cen]) {
			after = v;
		}
		else {
			totseen += subSize[v];
			go(v, subSize[v]);
		}
	}
	if (after != -1) {
		go(after, cSize-totseen);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	fill(marked, marked+maxn, false); //make sure it starts out empty
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0LL;
	go(1, n);
	cout << ans << endl;
	cin >> n;

}