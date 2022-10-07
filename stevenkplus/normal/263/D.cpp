#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define pb push_back

const int maxn = 100100;
vi conn[maxn];

bool vis[maxn];
int ar[maxn];
int pos[maxn];

int N, M, K;

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].pb(b);
		conn[b].pb(a);
	}

	int cur = 1;
	int x = 0;
	int m = 0;
	while (true) {
		vis[cur] = true;
		pos[cur] = x;
		ar[x] = cur;
		++x;

		int nxt = -1;
		repi(i, conn[cur]) {
			if (!vis[*i]) {
				nxt = *i;
				break;
			}
		}

		if (nxt == -1) {
			m = x;
			repi(i, conn[cur]) {
				m = min(m, pos[*i]);
			}
			break;
		} else {
			cur = nxt;
		}
	}
	int ans = x - m;
	printf("%d\n", ans);
	for (int i = m; i < x; ++i) {
		if (i - m) {
			printf(" ");
		}
		printf("%d", ar[i]);
	}
	printf("\n");
	return 0;
}