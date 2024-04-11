//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int arr[N];
int from[N],to[N];
vector<int> pr;
map<int,int> had;
int cap[N][N];
int mark[N];
int dfs(int v,int dest) {
	if(v == dest) return 1;
	if(mark[v]) return 0;
	mark[v] = 1;
	for(int i = 0; i <= dest;i++) {
		if(cap[v][i]) {
			if(dfs(i,dest)) {
				cap[v][i]--;
				cap[i][v]++;
				return 1;
			}
		}
	}
	return 0;
}
int solve(int p,int n,int m) {
	if(had[p]) return 0;
	had[p] = 1;
	for(int i = 0; i < n;i++) {
		int cnt = 0;
		while(arr[i] % p == 0) arr[i] /= p,cnt++;
		if(i & 1) cap[0][i + 1] = cnt, cap[i+1][0] = 0;
		else cap[i + 1][n + 1] = cnt, cap[n+1][i+1] = 0;
	}
	for(int i = 0; i < m;i++) {
		int u = from[i], v = to[i];
		if(v & 1) cap[u][v] = 1e9, cap[v][u] = 0;
		else cap[v][u] = 1e9 , cap[u][v] = 0;
	}
	int res = 0;
	while(1) {
		memset(mark,0,sizeof mark);
		int x = dfs(0,n+1);
		if(!x) break;
		res ++;
	}
	return res;
}
int main() {
	int n,m; cin >> n >> m;
	for(int i = 0; i < n;i++) cin >> arr[i];
	for(int i = 0; i < m;i++) {
		cin >> from[i] >> to[i]; from[i],to[i];
	}
	for(int i = 0; i < n;i++) {
		int x = arr[i];
		for(int j = 2; j * j <= x;j++) {
			int cnt = 0;
			while(x % j == 0) {
				x /= j;
				++cnt;
			}
			if(cnt) pr.push_back(j);
		}
		if(x - 1) pr.push_back(x);
	}
	sort(pr.begin(),pr.end());
	unique(pr.begin(),pr.end());
	int ans = 0;
	for(int cp = 0; cp < pr.size();++cp) {
		int cur = pr[cp];
		ans += solve(cur,n,m);
	}
	cout << ans << '\n';
}