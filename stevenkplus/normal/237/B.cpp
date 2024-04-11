#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

#define pb push_back
#define fi first
#define se second
#define sz(x) int((x).size())
const int MAXN = 5000;
pii map[MAXN];

pii ar[MAXN];
int Ms[MAXN];

int cur[MAXN];
int loc[MAXN];

int N;
vector<pii> moves;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", Ms + i);
	}
	int d = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < Ms[i]; ++j) {
			map[d] = pii(i + 1, j + 1);
			int tmp;
			scanf("%d", &tmp);
			ar[d] = pii(tmp, d);
			d++;
		}
	}
	sort(ar, ar + d);
	for(int i = 0; i < d; ++i) {
		cur[i] = ar[i].se;
		loc[ar[i].se] = i;
	}
	for(int i = 0; i < d; ++i) {
		if (loc[i] != i) {
			moves.pb(pii(loc[i], i));
			loc[cur[i]] = loc[i];
			cur[loc[i]] = cur[i];
			loc[i] = i;
			cur[i] = i;
		}
	}
	int size = sz(moves);
	printf("%d\n", size);
	for(int i = size - 1; i >= 0; --i) {
		printf("%d %d %d %d\n", map[moves[i].fi].fi, map[moves[i].fi].se, map[moves[i].se].fi, map[moves[i].se].se);
	}
	return 0;
}