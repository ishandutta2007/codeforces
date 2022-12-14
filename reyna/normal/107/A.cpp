//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
vector<pair<int,int> > in[Maxn],out[Maxn];
pair<int,int> dfs(int v,int Min = Maxn){
	if(!out[v].size()) return make_pair(v,Min);
	return dfs(out[v][0].first,min(Min,out[v][0].second));
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		in[--v].push_back(make_pair(--u,w));
		out[u].push_back(make_pair(v,w));
	}
	int ans = 0;
	for(int i = 0; i < n;i++){
		if(out[i].size() && !in[i].size()){
			ans++;
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n;i++){
		if(out[i].size() && !in[i].size()){
			pair<int,int> x = dfs(i);
			cout << i + 1 << ' ' << x.first + 1 << ' ' << x.second << endl;
		}
	}
	return 0;
}