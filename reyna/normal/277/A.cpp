//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 120;
int par[Maxn];
int lang[Maxn][Maxn];
int k[Maxn];
int find(int v){
	if(par[v] != v) return par[v] = find(par[v]);
	return v;
}
int unite(int u,int v){
	u = find(u),v = find(v);
	if(u == v) return 0; 
	par[u] = v;
	return 1;
}
int main(){
	int n,m;
	cin >> n >> m;
	int ans = n;
	int x = 0;
	for(int i = 0; i < n;i++) par[i] = i;
	for(int i = 0; i < n;i++){
		cin >> k[i];
		if(!k[i]) x++;
		for(int j = 0; j < k[i];j++){
			cin >> lang[i][j];
		}
		for(int e = 0; e < i;e++){
			bool f = 0;
			if(find(e) != find(i))
				for(int j = 0; j < k[e];j++){
					for(int r = 0; r < k[i];r++){
						if(lang[e][j] == lang[i][r]){
							ans -= unite(e,i);
							f = 1;
							break;
						}
					}
					if(f) break;
				}
		}
	}
	if(x == n) ans = n + 1;
	cout << ans - 1 << endl;
	return 0;
}