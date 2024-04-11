#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N, E, T, ass[50500], ord[50500], con[1100100];
vector<int> adj[50500], team[50500];
vector<pair<int,int>> edges;

/*
void dfs (int i) {
	int c[3] = {0, 0, 0};
	for (int j : adj[i]) if (ass[j]) {
		c[ass[j]]++;
	}
	if (c[1] > c[2]) ass[i] = 2;
	else ass[i] = 1;
	for (int j : adj[i]) if (!ass[j]) {
		dfs(j);
	}
}
*/

int main () {
	scanf("%d %d", &N, &E);
	fo(i, 0, E) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].PB(b), adj[b].PB(a);
		edges.PB(MP(a, b));
	}
	fo(i, 1, N+1) {
		int n; scanf("%d", &n);
		fo(j, 0, n) {
			int x; scanf("%d", &x);
			team[i].PB(x);
			T = max(T, x);
		}
	}

	//fo(i, 0, N) ord[i] = i+1;

	while (1) {
		/*
		fo(x, 0, N) {
			int i = ord[x];
			if (!ass[i]) dfs(i);
		}
		*/
		fo(i, 1, N+1) ass[i] = (rand()%2) + 1;
		int num = 0;
		fo(i, 0, E) {
			int a, b; tie(a,b) = edges[i];
			if (ass[a] != ass[b]) num++;
		}
		if (num >= (E+1)/2) {
			fo(rep, 0, 15) {
				fo(i, 1, T+1) con[i] = (rand()%2) + 1;
				bool gg = 1;
				fo(i, 1, N+1) {
					bool ok = 0;
					for (int j : team[i]) if (con[j] == ass[i]) {
						ok = 1; break;
					}
					if (!ok) {
						gg = 0;
						break;
					}
				}
				if (gg) {
					fo(i, 1, N+1) {
						for (int j : team[i]) if (con[j] == ass[i]) {
							if (i != 1) printf(" ");
							printf("%d", j); break;
						}
					}
					puts("");
					fo(i, 1, T+1) {
						if (i != 1) printf(" ");
						printf("%d", con[i]);
					}
					return 0;
				}
			}
		}
		//random_shuffle(ord, ord+N);
	}
	return 0;
}