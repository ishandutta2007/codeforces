//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Mod = 1e9 + 7;
const int Maxn = 1e5 + 9;
pair<int,int> par[Maxn];
pair<int,int> find(int v){
	if(par[v].first != v){
		pair<int,int> got = find(par[v].first);
		got.second %= Mod;
		return par[v] = make_pair(got.first,(got.second + par[v].second) % Mod);
	}
	return make_pair(v,0);
}
int unite(int u,int v,int x){
	pair<int,int> got = find(v);
	par[got.first] = make_pair(u,(got.second + x)%Mod);
	return (got.second + x) % Mod;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n;i++)
		par[i] = make_pair(i,0);
	int ans = 0;
	for(int i = 0; i < n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 0; j < k;j++){
			int v,x;
			scanf("%d%d",&v,&x);
			if(x < 0)
				x += Mod;
			ans += unite(i,--v,x);
			ans %= Mod;
			ans += Mod;
			ans %= Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}