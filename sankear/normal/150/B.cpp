#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

#define next _next

typedef long long ll;

const ll mp = (ll)(1e9 + 7);

int kr;
bool used[2020];
int first[2020];
int go[8000800], next[8000800];

inline void add(int a, int b){
	go[++kr] = b;
	next[kr] = first[a];
	first[a] = kr;
}

void dfs(int a){
	used[a] = true;
	for(int i = first[a]; i > 0; i = next[i]){
		if(!used[go[i]]){
			dfs(go[i]);
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, m, k;
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	if(k > n){
		ll ans = 1;
		for(int i = 0; i < n; i++){
			ans = (ans * m) % mp;
		}
		printf("%I64d\n", ans);
		return 0;
	}
	if(k == n){
		ll ans = 1;
		for(int i = 0; i < (n + 1) / 2; i++){
			ans = (ans * m) % mp;
		}
		printf("%I64d\n", ans);
		return 0;
	}
	kr = 0;
	for(int i = 0; i < n - k + 1; i++){
		int j = i, z = i + k - 1;
		while(j < z){
			add(z, j);
			add(j++, z--);
		}
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			dfs(i);
			sz++;
		}
	}
	ll ans = 1;
	for(int i = 0; i < sz; i++){
		ans = (ans * m) % mp;
	}
	printf("%I64d\n", ans);
	return 0;
}