#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

typedef pair < pii, int > piii;

#define maxn 51

const ll MD = 1000000007;
int dst[maxn][maxn][2];
bool used[maxn][maxn][2];
int p50, p100, n, k;
ll cnt[maxn][maxn][2];
ll ck[maxn][maxn];

void init() {
	ck[0][0] = 1LL;
	forn(i, 0, maxn) {
		ck[i][0] = 1LL;
		forn(j, 1, i + 1) {
			ck[i][j] = (ck[i - 1][j] + ck[i - 1][j - 1]) % MD;
		}
	}
}

inline void add(const int &x, const int &y, const int &pos, deque < piii > &q, const int &cur_dist) {
	used[x][y][pos] = true;
	dst[x][y][pos] = cur_dist;
	q.pb(mp(mp(x, y), pos));
}

int BFS(int x, int y, int pos, deque < piii > &q) {
	int cx = (!pos) ? x : p50 - x, cy = (!pos) ? y : p100 - y;
	int gx, gy;
	cnt[x][y][pos] %= MD;
	forn(i, 0, cx + 1) {
		forn(j, 0, cy + 1) {
			if (!(i + j) || 50 * i + 100 * j > k) continue;
			gx = (!pos) ? x - i : x + i, gy = (!pos) ? y - j : y + j; 
			if (!used[gx][gy][1 - pos])
				add(gx, gy, 1 - pos, q, dst[x][y][pos] + 1);
			if (dst[gx][gy][1 - pos] == dst[x][y][pos] + 1)
				cnt[gx][gy][1 - pos] += cnt[x][y][pos] * ck[cx][i] % MD * ck[cy][j] % MD; 
		}
	}
	return 0;
}

int main() {
	init();
	scanf("%d%d", &n, &k);
	forn(i, 0, n) {
		int a;
		scanf("%d", &a);
		if (a == 50) ++p50; else ++p100;
	}
	deque < piii > q;
	add(p50, p100, 0, q, 0);
	cnt[p50][p100][0] = 1LL;
	while (!q.empty()) {
		piii cur = q.front();
		q.pop_front();
		BFS(cur.first.first, cur.first.second, cur.second, q);
	}
	if (!used[0][0][1]) {
		printf("-1\n0\n");
		return 0;
	}
	printf("%d\n"LLD"\n", dst[0][0][1], cnt[0][0][1]);
	return 0;
}