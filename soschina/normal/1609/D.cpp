#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 1e3 + 1;

int n, d, u, v, x, y, fa[N], sz[N], cnt;

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

vector<int> vec;

int main(){
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	while(d--){
		scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if(u == v) cnt++;
		else{
			fa[v] = u;
			sz[u] += sz[v];
		}
		vec.clear();
		for(int i = 1; i <= n; i++)
			if(find(i) == i) vec.push_back(sz[i]);
		sort(vec.begin(), vec.end(), greater<int>());
		int ans = 0;
		for(int i = 0; i <= min(cnt, (int) vec.size() - 1); i++)
			ans += vec[i];
		printf("%d\n", ans - 1);
	}
	return 0;
}