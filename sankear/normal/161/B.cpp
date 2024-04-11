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
#include <queue>

using namespace std;

#define pb push_back

bool used[1010], good[1010];
int perm[1010], c[1010], t[1010];
vector <int> v[1010];

bool cmp(int a, int b){
	return c[a] < c[b];
}

int main(){
	//freopen("bidirected.in", "r", stdin);
	//freopen("bidirected.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &c[i], &t[i]);
		perm[i] = i;
	}
	sort(perm, perm + n, cmp);
	int sz = 0;
	for(int i = n - 1; i >= 0; i--){
		if(t[perm[i]] == 1){
			v[sz].pb(perm[i]);
			good[sz] = true;
			sz++;
			used[i] = true;
			if(sz == k){
				break;
			}
		}
	}
	for(int i = sz; i < k; i++){
		for(int j = 0; j < n; j++){
			if(!used[j]){
				used[j] = true;
				v[i].pb(perm[j]);
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(!used[i]){
			v[k - 1].pb(perm[i]);
		}
	}
	double ans = 0;
	for(int i = 0; i < k; i++){
		sort(v[i].begin(), v[i].end(), cmp);
		if(good[i]){
			ans += ((double)c[v[i][0]]) / 2;
			for(int j = 1; j < (int)v[i].size(); j++){
				ans += c[v[i][j]];
			}
			continue;
		}
		for(int j = 0; j < (int)v[i].size(); j++){
			ans += c[v[i][j]];
		}
	}
	printf("%.1lf\n", ans);
	for(int i = 0; i < k; i++){
		printf("%d", v[i].size());
		for(int j = 0; j < (int)v[i].size(); j++){
			printf(" %d", v[i][j] + 1);
		}
		printf("\n");
	}
	return 0;
}