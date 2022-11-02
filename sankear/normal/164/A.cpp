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

#define pb push_back

const int maxn = 100100;

int cur;
bool good[maxn], can[maxn];
int f[maxn];
vector <int> v[maxn], rv[maxn];

void dfs(int a){
	can[a] = true;
	for(int i = 0; i < (int)v[a].size(); i++){
		if(f[v[a][i]] != 1 && !can[v[a][i]]){
			dfs(v[a][i]);
		}
	}
}

void rdfs(int a){
	good[a] = true;
	for(int i = 0; i < (int)rv[a].size(); i++){
		if(f[rv[a][i]] != 1 && !good[rv[a][i]]){
			rdfs(rv[a][i]);
		}
	}
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &f[i]);
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].pb(b);
		rv[b].pb(a);
	}
	for(int i = 0; i < n; i++){
		if(f[i] == 1){
			for(int j = 0; j < (int)v[i].size(); j++){
				if(f[v[i][j]] != 1 && !can[v[i][j]]){
					dfs(v[i][j]);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(f[i] == 2 && !good[i]){
			rdfs(i);
		}
	}
	for(int i = 0; i < n; i++){
		if(f[i] == 1){
			bool fl = false;
			for(int j = 0; j < (int)v[i].size(); j++){
				if(f[v[i][j]] != 1 && good[v[i][j]]){
					fl = true;
					break;
				}
			}
			if(fl){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
			continue;
		}
		if(good[i] && can[i]){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}