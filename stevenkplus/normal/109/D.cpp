#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100100;

pii ar[MAXN];
bool vis[MAXN];

int N;
int ans = 0;

int X[2 * MAXN];
int Y[2 * MAXN];

void mv(int a, int b) {
	X[ans] = a;
	Y[ans] = b;
	++ans;
}

bool lucky(int x) {
	while (x) {
		int dig = x % 10;
		x /= 10;
		if (dig != 4 && dig != 7) return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ar[i] = pii(tmp, i);
	}

	sort(ar + 1, ar + N + 1);

	int luck = 0;
	for(int i = 1; i <= N; ++i) {
		if (lucky(ar[i].first)) {
			luck = ar[i].second;
			break;
		}
	}

	if (!luck) {
		for(int i = 1; i + 1 <= N; ++i) {
			if (ar[i].second > ar[i + 1].second) {
				printf("-1\n");
				return 0;
			}
		}
		printf("0\n");
	} else {
		int cur = luck;
		while (ar[cur].second != luck) {
			vis[cur] = true;
			mv(cur, ar[cur].second);
			cur = ar[cur].second;
		}
		vis[cur] = true;
		luck = cur;

		for(int i = 1; i <= N; ++i) {
			if (!vis[i]) {
				mv(luck, i);
				cur = i;
				while (ar[cur].second != i) {
					vis[cur] = true;
					int nxt = ar[cur].second;
					mv(cur, nxt);
					cur = nxt;
				}
				vis[cur] = true;

				mv(luck, cur);
			}
		}

		printf("%d\n", ans);
		for(int i = 0; i < ans; ++i) {
			printf("%d %d\n", X[i], Y[i]);
		}
	}

	return 0;
}