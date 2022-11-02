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

vector <int> v1[1010], v2[1010];

int main(){
	//freopen("bidirected.in", "r", stdin);
	//freopen("bidirected.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v1[y].pb(x);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v2[b].pb(a);
	}
	int a = 0, b = 0;
	for(int i = 1; i <= 1000; i++){
		sort(v1[i].begin(), v1[i].end());
		sort(v2[i].begin(), v2[i].end());
		int res = 0, z = 0;
		for(int j = 0; j < (int)v1[i].size(); j++){
			while(z < (int)v2[i].size() && v2[i][z] < v1[i][j]){
				z++;
			}
			if(z < (int)v2[i].size() && v1[i][j] == v2[i][z]){
				res++;
				z++;
			}
		}
		b += res;
		a += min(v1[i].size(), v2[i].size());
	}
	printf("%d %d\n", a, b);
	return 0;
}