#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 10010;

set<pii> myset;
int centers[MAXN];
int rads[MAXN];
int hits[MAXN];

int N, M;
int cnt = 0;

bool hit(int x, int y, int circ) {
	int dx = centers[circ] - x;
	int dist = dx * dx + y * y;
	return dist <= rads[circ] * rads[circ];
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d %d", centers + i, rads + i);
		myset.insert(pii(centers[i] + rads[i], i));
		hits[i] = -1;
	}

	scanf("%d", &M);
	for(int i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);

		typeof(myset.begin()) it = myset.lower_bound(pii(x, 0));
		if (it != myset.end()) {
			int c = it->second;
			if (hit(x, y, c)) {
				if (hits[c] == -1) {
					hits[c] = i;
					++cnt;
				}
			}
			++it;
			if (it != myset.end()) {
				c = it->second;
				if (hit(x, y, c)) {
					if (hits[c] == -1) {
						hits[c] = i;
						++cnt;
					}
				}
			}
		}
	}

	printf("%d\n", cnt);
	for(int i = 0; i < N; ++i) {
		if (i) printf(" ");
		printf("%d", hits[i]);
	}
	printf("\n");
	return 0;
}