#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E3 + 10, MAXK = 2E3 + 10;

int n, m, K;
int a[MAXN][MAXN];

bool state[MAXK];
vector<ll> b[MAXK];
int head[MAXK][2], tail[MAXK][2];
vector<PII> c[MAXK];

void add(int x, int y, bool flag){
	const static int mask = (1 << 16) - 1;
	if (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] >> 16)
		c[a[x][y] >> 16].push_back(PII(a[x][y] & mask, flag));
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= K; ++i){
		int len, x, y, w;
		state[i] = true;
		scanf("%d", &len);
		b[i].push_back(0);

		for (int w, j = 1; j <= len; ++j){
			scanf("%d%d%d", &x, &y, &w);
			a[x][y] = i << 16 | j;
			b[i].push_back(b[i].back() + w);
			if (j == 1)
				head[i][0] = x, head[i][1] = y;
			if (j == len)
				tail[i][0] = x, tail[i][1] = y;
		}
	}

	int q, x1, y1, x2, y2;
	char com[10];
	scanf("%d", &q);
	for (int qi = 0; qi < q; ++qi){
		scanf("%s%d", com, &x1);
		if (com[0] == 'S')
			state[x1] ^= 1;
		else{
			scanf("%d%d%d", &y1, &x2, &y2);
			for (int i = 1; i <= K; ++i)
				c[i].clear();
			for (int i = x1; i <= x2; ++i){
				add(i, y1 - 1, false), add(i, y2 + 1, false);
				add(i, y1, true), add(i, y2, true);
			}
			for (int i = y1; i <= y2; ++i){
				add(x1 - 1, i, false), add(x2 + 1, i, false);
				add(x1, i, true), add(x2, i, true);
			}

			ll ans = 0;
			for (int i = 1; i <= K; ++i){
				if (!state[i])
					continue;

				c[i].push_back(PII(1, x1 <= head[i][0] && head[i][0] <= x2 && y1 <= head[i][1] && head[i][1] <= y2));
				c[i].push_back(PII(b[i].size() - 1, x1 <= tail[i][0] && tail[i][0] <= x2 && y1 <= tail[i][1] && tail[i][1] <= y2));
				sort(c[i].begin(), c[i].end());
				for (int k, j = 0; j < c[i].size(); j = k){
					for (k = j + 1; k < c[i].size() && c[i][j].nd == c[i][k].nd; ++k);
					if (c[i][j].nd)
						ans += b[i][c[i][k - 1].st] - b[i][c[i][j].st - 1];
				}
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}