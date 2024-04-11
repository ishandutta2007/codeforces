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

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
char s[5050];
int used[5050], p[5050];
bool r[5050][5050];

inline bool check(int a, int b, int c){
	return r[a][b] && r[b][c] && r[c][a];
}

void dfs(int a){
	used[a] = 1;
	for(int i = 0; i < n; i++){
		if(r[a][i]){
			if(used[i] == 0){
				p[i] = a;
				dfs(i);
				continue;
			}
			if(used[i] == 1){
				while(!check(i, p[a], a)){
					a = p[a];
				}
				printf("%d %d %d\n", i + 1, p[a] + 1, a + 1);
				exit(0);
			}
		}
	}
	used[a] = 2;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d\n", &n);
	for(int i = 0; i < n; i++){
		scanf("%s\n", s);
		for(int j = 0; j < n; j++){
			if(s[j] == '1'){
				r[i][j] = true;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(used[i] == 0){
			dfs(i);
		}
	}
	printf("-1\n");
  return 0;
}