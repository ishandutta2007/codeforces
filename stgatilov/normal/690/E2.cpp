//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int PCNT = 16;
const int SIZE = 640;
const int RAD = 2;

int h, w, k, hp;
int matr[SIZE][SIZE];
int pieces[PCNT][SIZE][SIZE];
int pfilt[PCNT][SIZE][SIZE];

int cost[PCNT][PCNT];

int res[1<<PCNT][PCNT];
int par[1<<PCNT][PCNT];

inline int sqr(int x) { return x*x; }

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int q;
	scanf("%d", &q);

	for (int tt = 0; tt < q; tt++) {
		scanf("%d%d%d", &h, &w, &k);
		hp = h / k;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				scanf("%d", &matr[i][j]);
				pieces[i/hp][i%hp][j] = matr[i][j];
			}

		for (int u = 0; u < k; u++)
			for (int i = 0; i < hp; i++)
				for (int j = 0; j < w; j++) {
					int sum = 0, cnt = 0;
					for (int di = -RAD; di <= RAD; di++)
						for (int dj = -RAD; dj <= RAD; dj++) {
							int ni = i + di;
							int nj = j + dj;
							if (ni >= 0 && ni < hp && nj >= 0 && nj < w) {
								sum += pieces[u][ni][nj];
								cnt++;
							}
						}
					pfilt[u][i][j] = (sum + cnt/2) / cnt;
				}
		
		for (int u = 0; u < k; u++)
			for (int v = 0; v < k; v++) {
				int sum = 0;
				for (int i = 0; i < w; i++)
					sum += sqr(pfilt[u][hp-1][i] - pfilt[v][0][i]);
//					sum += sqr(pieces[u][hp-1][i] - pieces[v][0][i]);
				cost[u][v] = sum;
			}
		
		memset(res, 63, sizeof(res));
		for (int i = 0; i < k; i++) {
			res[1<<i][i] = 0;
			par[1<<i][i] = -1;
		}
		for (int m = 1; m < 1<<k; m++)
			for (int u = 0; u < k; u++) if (m & (1<<u)) {
				int tres = res[m][u];
				for (int v = 0; v < k; v++) if (!(m & (1<<v))) {
					int nm = m | (1<<v);
					int nres = tres + cost[u][v];
					if (res[nm][v] > nres) {
						res[nm][v] = nres;
						par[nm][v] = u;
					}
				}
			}


		vector<int> sol;

		int m = (1<<k) - 1;
		int u = 0;
		for (int i = 0; i < k; i++)
			if (res[m][i] < res[m][u])
				u = i;

		while (m > 0) {
			int pu = par[m][u];
			sol.push_back(u);
			m ^= (1<<u);
			u = pu;
		}
		assert(sol.size() == k);

		reverse(sol.begin(), sol.end());
		vector<int> inv(k);
		for (int i = 0; i < k; i++)
			inv[sol[i]] = i;

		for (int i = 0; i < k; i++)
			printf("%d ", inv[i] + 1);
		printf("\n");
	}

	return 0;
}