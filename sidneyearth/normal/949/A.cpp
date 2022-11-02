#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 200100;
char s[maxn];
int f[maxn], g[maxn];
vector<int> G[maxn];
int Find(int *f, int u){ return u == f[u] ? u : f[u] = Find(f, f[u]); }
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n + 1; i++){
		f[i] = i + (s[i] == '1');
		g[i] = i + (s[i] == '0');
	}
	int c = 0;
	for(int i = 1; i <= n; i++)
		if(Find(f, i) == i){
			G[c].push_back(i);
			int u = i;
			while(u <= n){
				int x = Find(g, u);
				int y = Find(f, x);
				if(y <= n){
					G[c].push_back(x);
					G[c].push_back(y);
					u = y;
					g[x] = x + 1;
					f[y] = y + 1;
				}
				u = y;
			}
			c++;
		}
		else if(Find(g, i) == i){
			printf("-1\n");
			return 0;
		}
	printf("%d\n", c);
	for(int i = 0; i < c; i++){
		printf("%d ", G[i].size());
		for(int j = 0; j < G[i].size(); j++)
			printf("%d ", G[i][j]);
		printf("\n");
	}
	return 0;
}