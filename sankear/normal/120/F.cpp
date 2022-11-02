#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

int k;
bool used[200];
int first[200], d[200];
int go[400], next[400];

inline void add(int a, int b){
	go[++k] = b;
	next[k] = first[a];
	first[a] = k;
}

void dfs(int a, int b){
	used[a] = true;
	d[a] = b;
	for(int i = first[a]; i > 0; i = next[i]){
		if(!used[go[i]]){
			dfs(go[i], b + 1);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			first[j] = 0;
		}
		k = 0;
		for(int j = 0; j < m - 1; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			add(a, b);
			add(b, a);
		}
		int res = 0;
		for(int j = 0; j < m; j++){
			for(int z = 0; z < m; z++){
				used[z] = false;
			}
			dfs(j, 0);
			int cur = 0;
			for(int z = 0; z < m; z++){
				cur = max(cur, d[z]);
			}
			res = max(res, cur);
		}
		ans += res;
	}
	printf("%d\n", ans);
	return 0;
}