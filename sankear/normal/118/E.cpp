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
bool used[100100];
bool use[600600];
int first[100100], col[100100], lst[100100], tin[100100];
int a[600600], b[600600], go[600600], num[600600], next[600600];

inline void add1(int a, int b, int c){
	go[++k] = b;
	num[k] = c;
	next[k] = first[a];
	first[a] = k;
}

inline void add2(int a, int b){
	go[++k] = b;
	next[k] = first[a];
	first[a] = k;
}

void dfs1(int a){
	used[a] = true;
	tin[a] = ++k;
	for(int i = first[a]; i > 0; i = next[i]){
		if(!used[go[i]]){
			use[num[i]] = true;
			dfs1(go[i]);
		}
	}
}

void dfs2(int a){
	used[a] = true;
	for(int i = first[a]; i > 0; i = next[i]){
		if(!used[go[i]]){
			dfs2(go[i]);
		}
	}
	lst[k++] = a;
}

void dfs3(int a){
	col[a] = k;
	for(int i = first[a]; i > 0; i = next[i]){
		if(col[go[i]] == 0){
			dfs3(go[i]);
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}
	k = 0;
	for(int i = 0; i < m; i++){
		add1(a[i], b[i], i);
		add1(b[i], a[i], i);
	}
	k = 0;
	dfs1(0);
	for(int i = 0; i < m; i++){
		if(use[i]){
			if(tin[a[i]] > tin[b[i]]){
				swap(a[i], b[i]);
			}
		}
		else{
			if(tin[a[i]] < tin[b[i]]){
				swap(a[i], b[i]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		first[i] = 0;
	}
	k = 0;
	for(int i = 0; i < m; i++){
		add2(a[i], b[i]);
	}
	for(int i = 0; i < n; i++){
		used[i] = false;
	}
	k = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			dfs2(i);
		}
	}
	for(int i = 0; i < n; i++){
		first[i] = 0;
	}
	k = 0;
	for(int i = 0; i < m; i++){
		add2(b[i], a[i]);
	}
	k = 0;
	for(int i = n - 1; i >= 0; i--){
		if(col[lst[i]] == 0){
			k++;
			dfs3(lst[i]);
		}
	}
	if(k != 1){
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < m; i++){
		printf("%d %d\n", a[i] + 1, b[i] + 1);
	}
	return 0;
}