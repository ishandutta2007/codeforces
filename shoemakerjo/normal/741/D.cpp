// #include <bits/stdc++.h>

// using namespace std;
// const int maxn = 500010; //change to a const
// const int inf = 1000000000;
// int n;

// char let[maxn]; 
// int subsize[maxn]; 
// int mask[maxn]; 
// vector<int> adj[maxn];
// int ans[maxn];
// int dep[maxn];
// int big[maxn];
// int dfs_time;
// int st[maxn], ft[maxn];
// int mcur, cur, cd, tv; 
// int vals[maxn];
// int bag[1 << 22]; 

// void preprocess(int u) {
// 	vals[dfs_time] = u;
// 	st[u] = dfs_time++; //starting index (grab value before)

// 	subsize[u] = 0;
// 	big[u] = -1;
// 	for (auto v : adj[u]) {
// 		dep[v] = dep[u]+1;
// 		mask[v] = mask[u] ^ (1 << let[v] - 'a');
// 		preprocess(v);
// 		subsize[u] += subsize[v];
// 		if (big[u] == -1 || subsize[v] > subsize[big[u]]) {
// 			big[u] = v;
// 		}
// 	}
// 	ft[u] = dfs_time; 
// }

// void dfs(int u, bool keep) { 
// 	ans[u] = 0;
// 	for (auto v : adj[u]) {
// 		if (v != big[u]) {
// 			dfs(v, false); 
// 			ans[u] = max(ans[u], ans[v]); 
// 		}
// 	}

// 	if (big[u] != -1) { 
// 		dfs(big[u], true); 
// 		ans[u] = max(ans[u], ans[big[u]]);
// 	}

// 	bag[mask[u]] = max(bag[mask[u]], dep[u]);

// 	for (auto v : adj[u]) {
// 		if (v != big[u]) {
// 			for (int i = st[v]; i < ft[v]; i++) {
// 				cur = vals[i];
// 				for (int j = 0; j < 22; j++) {
// 					ans[u] = max(ans[u], dep[cur] + bag[mask[cur] ^ (1 << j)] - 2*dep[u]); 	
// 				}
// 				ans[u] = max(ans[u], dep[cur] + bag[mask[cur]] - 2*dep[u]);
// 			}
// 			for (int i = st[v]; i < ft[v]; i++) {
// 				bag[mask[vals[i]]] = max(bag[mask[vals[i]]], dep[vals[i]]);
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 22; i++) { 
// 		tv = mask[u] ^ (1 << i);
// 		ans[u] = max(ans[u], bag[tv]-dep[u]);
// 	} 
// 	ans[u] = max(ans[u], bag[mask[u]] - dep[u]);
	
// 	if (!keep) {
// 		for (int i = st[u]; i < ft[u]; i++) {
// 			bag[mask[vals[i]]] = -inf; 
// 		}
// 	}
// }

// int main() {
// 	// ios_base::sync_with_stdio(false);
// 	// cin.tie(NULL);
// 	// cout.tie(NULL);
// 	scanf("%d", &n);
// 	int p;
// 	for (int i = 2; i <= n; i++) {
// 		scanf("%d %c", &p, &let[i]);
// 		adj[p].push_back(i); 
// 	}
// 	dfs_time = 0;
// 	dep[1] = 1; //mixing up how we do depth  
// 	mask[1] = 0; //top of the thing
// 	preprocess(1);
// 	fill(begin(bag), end(bag), -inf); 
// 	dfs(1, true);
// 	for (int i  = 1; i <= n; i++) {
// 		printf("%d ", ans[i]);
// 	}
// 	// cout << endl;
// 	printf("\n");
// 	// cin >> n;
// }

//THIS IS TOO STUPID I CONCEDE
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 17, z = 22, inf = 1e9;
vector<int> adj[maxn];
int n, big[maxn], a[maxn], sz[maxn], cur, ans[maxn], h[maxn], bag[1 << z];
int st[maxn], ft[maxn], ver[maxn], dfs_time;
char s[maxn];
void pre_dfs(int v = 0){
    st[v] = dfs_time++;
    ver[ st[v] ] = v;
    sz[v] = 1, big[v] = -1;
    for(auto u : adj[v]){
	a[u] = (1 << s[u] - 'a') ^ a[v];
	h[u] = h[v] + 1;
	pre_dfs(u);
	sz[v] += sz[u];
	if(big[v] == -1 || sz[u] > sz[ big[v] ])
	    big[v] = u;
    }
    ft[v] = dfs_time;
}
void dfs(int v = 0, bool cl = 0){
    for(auto u : adj[v])
	if(u != big[v])
	    dfs(u, 1), ans[v] = max(ans[v], ans[u]);
    if(big[v] != -1)
	dfs(big[v], 0), ans[v] = max(ans[v], ans[ big[v] ]);
    for(auto u : adj[v])
	if(u != big[v]){
	    for(int p = st[u]; p < ft[u]; p++){
		int x = ver[p];
		cur = max(cur, h[x] + bag[ a[x] ] - 2 * h[v]);
		for(int i = 0; i < z; i++)
		    cur = max(cur, h[x] + bag[ a[x] ^ (1 << i) ] - 2 * h[v]);
	    }
	    for(int p = st[u]; p < ft[u]; p++)
		bag[ a[ ver[p] ] ] = max(bag[ a[ ver[p] ] ], h[ ver[p] ]);
	}
    cur = max(cur, bag[ a[v] ] - h[v]);
    for(int i = 0; i < z; i++)
	cur = max(cur, bag[ a[v] ^ (1 << i) ] - h[v]);
    bag[ a[v] ] = max(bag[ a[v] ], h[v]);
    ans[v] = max(ans[v], cur);
    if(cl){
	for(int p = st[v]; p < ft[v]; p++)
	    bag[ a[ ver[p] ] ] = -inf;
	cur = 0;
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1, p; i < n; i++){
	scanf("%d %c", &p, &s[i]), p--;
	adj[p].push_back(i);
    }
    fill(begin(bag), end(bag), -inf);
    pre_dfs();
    dfs();
    for(int i = 0; i < n; i++)  printf("%d ", ans[i]);
    return 0;
}