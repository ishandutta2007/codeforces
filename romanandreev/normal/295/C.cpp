#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <queue>


#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
const int md = (int)1e9 + 7;
ll cnk[100][100];
int dp[100][100][2];
ll dp2[100][100][2];

int n, k;
int main()
{
	#ifdef home
		assert(freopen(TASK".in", "r", stdin));
		assert(freopen(TASK".out", "w", stdout));
	#endif
	for (int i = 0; i <= 60; i++) {
		cnk[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % md;
		}
	}
	scanf("%d %d", &n, &k);
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 50) a++;
		if (x == 100) b++;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j][0] = inf;
			dp2[i][j][0] = 0;
			dp[i][j][1] = inf;
			dp2[i][j][1] = 0;
		}
	}
	dp[0][0][0] = 0;
	dp2[0][0][0] = 1;
	queue<pair<pi, int> > q;
	q.push(mp(mp(0, 0), 0));
	while (!q.empty()) {
		pair<pi, int> v = q.front();
		q.pop();
		if (v.y == 0) {
			for (int i = 0; i <= a - v.x.x; i++) {
				for (int j = 0; j <= b - v.x.y; j++) {
					if (i + j > 0 && i * 50 + j * 100 <= k) {
						pair<pi, int> nv = mp(mp(v.x.x + i, v.x.y + j), 1);
						if (dp[nv.x.x][nv.x.y][nv.y] == inf) {
							dp[nv.x.x][nv.x.y][nv.y] = dp[v.x.x][v.x.y][v.y] + 1;
							q.push(nv);
						}
						if (dp[nv.x.x][nv.x.y][nv.y] == dp[v.x.x][v.x.y][v.y] + 1) {
							dp2[nv.x.x][nv.x.y][nv.y] = (dp2[nv.x.x][nv.x.y][nv.y] +  (ll)((ll)dp2[v.x.x][v.x.y][v.y] * cnk[a - v.x.x][i]) % md * cnk[b - v.x.y][j]) % md;
						}
					}
				}
			}
		} else {
			for (int i = 0; i <= v.x.x; i++) {
				for (int j = 0; j <= v.x.y; j++) {
					if (i + j > 0 && i * 50 + j * 100 <= k) {
						pair<pi, int> nv = mp(mp(v.x.x - i, v.x.y - j), 0);
						if (dp[nv.x.x][nv.x.y][nv.y] == inf) {
							dp[nv.x.x][nv.x.y][nv.y] = dp[v.x.x][v.x.y][v.y] + 1;
							q.push(nv);
						}
						if (dp[nv.x.x][nv.x.y][nv.y] == dp[v.x.x][v.x.y][v.y] + 1) {
							dp2[nv.x.x][nv.x.y][nv.y] = (dp2[nv.x.x][nv.x.y][nv.y] +  (ll)((ll)dp2[v.x.x][v.x.y][v.y] * cnk[v.x.x][i]) % md * cnk[v.x.y][j]) % md;
						}
					}
				}
			}
		}
	}
	if (dp[a][b][1] == inf) {
		printf("-1\n0\n");
		return 0;
	}
	printf("%d\n", dp[a][b][1]);
	printf("%I64d\n", dp2[a][b][1] % md);
	#ifdef home
		eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
	#endif
	return 0;
}