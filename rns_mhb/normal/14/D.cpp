#include <bits/stdc++.h>
using namespace std;
#define N 205

bool vis[N];
vector <int> leaf, st, fs;
vector <int> v[N];
int val, dist[N][N], ans;

void dfs(int k){
	vis[k] = 1;
	int sz = v[k].size();
	for(int i = 0; i < sz; i++){
		if(!vis[v[k][i]]){
			dist[val][v[k][i]] = dist[val][k] + 1;
			dfs(v[k][i]);
		}
	}
}

int main(){
	int i, j, ii, jj, k, mxst, mxfs, siz, szst, szfs, n, sz;
	scanf("%d", &n);
	i = n - 1;
	while(i--){
		scanf("%d %d", &ii, &jj);
		v[jj].push_back(ii);
		v[ii].push_back(jj);
	}
	for(i = 1; i <= n; i++) if(v[i].size() == 1) leaf.push_back(i);
	sz = leaf.size();
	for(i = 0; i < sz; i++){
		memset(vis, 0, sizeof vis);
		val = leaf[i];
		dist[leaf[i]][leaf[i]] = 0;
		dfs(leaf[i]);
	}
	for(i = 1; i <= n; i++){
		siz = v[i].size();
		for(j = 0; j < siz; j++){
			if(i < v[i][j]) continue;
			st.clear(); fs.clear();
			for(k = 0; k < sz; k++){
				if(dist[leaf[k]][i] > dist[leaf[k]][v[i][j]]) st.push_back(leaf[k]);
				else fs.push_back(leaf[k]);
			}
			st.push_back(v[i][j]);
			fs.push_back(i);
			mxst = 0; mxfs = 0;
			szst = st.size(); szfs = fs.size();
			for(ii = 0; ii < szst; ii++) for(jj = ii + 1; jj < szst; jj++) mxst = max(mxst, dist[st[ii]][st[jj]]);
			for(ii = 0; ii < szfs; ii++) for(jj = ii + 1; jj < szfs; jj++) mxfs = max(mxfs, dist[fs[ii]][fs[jj]]);
			ans = max(ans, mxst * mxfs);
		}
	}
	printf("%d", ans);
}