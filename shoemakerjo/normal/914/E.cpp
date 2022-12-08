#include <bits/stdc++.h>

using namespace std;

#define maxn 200010
#define ll long long

string lab;
ll ans[maxn];
int subSize[maxn];
bool marked[maxn];
int pars[maxn];
ll res[maxn];

vector<vector<int>> adj(maxn);

int act[21];
ll curin[9000000];
int n;

void dfscalc(int u, int p) {
	act[lab[u]-'a']++;
	// cout << "just added in " << u << "  " <<  lab[u]-'a' << "   " << act[lab[u]-'a'] <<  endl;
	// cout << "parent  : " << u << "  " << p << endl;

	res[u] = 0LL;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p || marked[v]) continue;
		dfscalc(v, u);
		res[u] += res[v];
	}
	int mask = 0;
	for (int i = 0; i < 21; i++) {
		// if (i < 4) cout << "        " << u << " " << i << " " << act[i] << endl;
		if ( (act[i]%2) == 1) {
			mask |= (1 << i);
		}
	}
	res[u] += curin[mask];
	for (int i = 0; i < 21; i++) {

		int dm = (mask ^ (1 << i));
		res[u] += curin[dm];
	}
	// cout << "u    " << u << "  " <<  mask << endl;
	//recursive cleanup
	act[lab[u]-'a']--;
	ans[u] += res[u];
}

void delt(int u, int p, ll ch) {
	act[lab[u]-'a']++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p || marked[v]) continue;
		delt(v, u, ch);
	}
	int mask = 0;
	for (int i = 0; i < 21; i++) {
		if ( (act[i]%2) == 1) {
			mask |= (1 << i);
		}
	}
	curin[mask] += ch;
	act[lab[u]-'a']--;
}

void calc(int u) {
	// cout << "calculating for  " << u << endl;
	for (int i = 0; i < 21; i++) {
		act[i] = 0;
	}
	
	curin[0]+=1LL;
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!marked[v]) {
			act[lab[u]-'a']++; //calculate and include root
			dfscalc(v, u);
			ans[u] += res[v]; 
			act[lab[u]-'a']--; //delta without the root
			delt(v, u, 1);
		}
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!marked[v]) {
			delt(v, u, -1);
		}
	}
	
	curin[0] -= 1LL;
	for (int i = adj[u].size()-1; i >= 0; i--) {
		int v = adj[u][i];
		if (!marked[v]) {
			act[lab[u]-'a']++;
			dfscalc(v, u);
			act[lab[u]-'a']--;
			delt(v, u, 1);
		}	
	}
	for (int i = adj[u].size()-1; i >= 0; i--) {
		int v = adj[u][i];
		if (!marked[v]) {
			// dfscalc(v, u);
			delt(v, u, -1); //delta without the root
		}	
	}

}


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
	cin >> n;
	fill(curin, curin+9000000, 0LL);
	int a, b;
	for (int i = 0; i <= n; i++) {
		marked[i] = false;
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> lab;
	fill(ans, ans+maxn, 0LL);
	lab = " " + lab;
	// cout << "LAB ORIGINAL:" << lab << endl;
	go(1, n); 
	for (int i = 1; i <= n; i++) {
		cout << ans[i]+1LL;
		if (i != n) cout << " ";
	}
	cout << endl;
	cin >> n;
}