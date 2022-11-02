#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
#define M 300010

vector <int> v[M];
int n, m, flag[M];

int deg[M];

void solve(){
	int i, j;
	for(int ii = 1; ii <= n; ii++){
		i = ii;
		while(1){
			if(deg[i] <= 1) break;
			flag[i] = 1 - flag[i];
			deg[i] = 0;
			for(j = 0; j < v[i].size(); j++){
				int x = v[i][j];
				if(flag[x] == flag[i]) {deg[x]++; deg[i]++;}
				else deg[x]--;
			}
			for(j = 0; j < v[i].size(); j++){
				int x = v[i][j];
				if(flag[x] == flag[i] && deg[x] > 1) {i = x; break;}
			}
		}
	}
}

int main(){
	int i, x, y, j;

//	freopen("C.in", "r", stdin);
//	freopen("C.out", "w", stdout);

	scanf("%d %d", &n, &m);

	for(i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		v[x].push_back(y); v[y].push_back(x);
		deg[x]++; deg[y]++;
	}

	solve();

	for(i = 1; i <= n; i++){
		int cn = 0;
		for(j = 0; j < v[i].size(); j++){
			x = v[i][j];
			if(flag[x] == flag[i]) cn++;
		}
		if(cn > 1) fprintf(stderr, "wrong answer\n");
	}
	for(i = 1; i <= n; i++) printf("%d", flag[i]);
	return 0;
}