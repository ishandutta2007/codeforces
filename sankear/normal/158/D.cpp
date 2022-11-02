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

const int inf = (int)1e9;

int n, step, sum;
bool used[20200];
int a[20200];

void dfs(int v){
	sum += a[v];
	used[v] = true;
	v = (v + step) % n;
	if(!used[v]){
		dfs(v);
	}
}

int main(){
	//freopen("contest.in", "r", stdin);
	//freopen("contest.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = -inf;
	for(int i = 3; i <= n; i++){
		if(n % i == 0){
			step = n / i;
			for(int j = 0; j < n; j++){
				used[j] = false;
			}
			for(int j = 0; j < n; j++){
				if(!used[j]){
					sum = 0;
					dfs(j);
					ans = max(ans, sum);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}