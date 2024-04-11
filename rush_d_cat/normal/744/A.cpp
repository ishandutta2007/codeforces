#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int par[N], sz[N], c[N];
int find(int x) {
	return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	if(find(x)!=find(y)){
		sz[find(y)] += sz[find(x)];
		par[find(x)]=find(y);
	}
}

int main() {
	for(int i=0;i<N;i++) {
		par[i]=i; sz[i]=1;
	}	
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m;i++) {
		int u,v; scanf("%d%d",&u,&v);
		unite(u,v);
	}
	vector<int> vec;
	for(int i=1;i<=k;i++) {
		vec.push_back(sz[find(c[i])]);
	}
	sort(vec.begin(), vec.end());
	int sum=0,sum2=0;
	for(int i=0;i<(int)vec.size()-1;i++){
		sum += vec[i];
		sum2 += vec[i] * (vec[i] - 1) / 2;
	} 

	int tot = sum2 + (n - sum) * (n - sum - 1) / 2;
	cout << tot - m << endl;
}