#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef pair<int, int> pii;

map< int, vector< pii > > vcuts, hcuts;
map< int, int > vlens, hlens;

int N, M, K;
int main() {
	scanf("%d %d %d", &N, &M, &K);

	int sum = 0;
	if ((N - 1) & 1) sum ^= M;
	if ((M - 1) & 1) sum ^= N;

	for(int i = 0; i < K; ++i) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (a == c) {
			if (b > d) swap(b, d);
			vcuts[a].push_back(pii(b, 1));
			vcuts[a].push_back(pii(d, -1));
		} else if (b == d) {
			if (a > c) swap(a, c);
			hcuts[b].push_back(pii(a, 1));
			hcuts[b].push_back(pii(c, -1));
		}
	}

	repi(i, vcuts) {
		vector<pii> &v = i->second;
		sort(v.begin(), v.end());
		int prv = 0, cnt = 0, len = 0;
		repi(j, v) {
			int cur = j->first;
			if (cnt == 0) len += cur - prv;
			cnt += j->second;
			prv = cur;
		}
		len += M - prv;
		vlens[i->first] = len;
		sum ^= M ^ len;
	}

	repi(i, hcuts) {
		vector<pii> &v = i->second;
		sort(v.begin(), v.end());
		int prv = 0, cnt = 0, len = 0;
		repi(j, v) {
			int cur = j->first;
			if (cnt == 0) len += cur - prv;
			cnt += j->second;
			prv = cur;
		}
		len += N - prv;
		hlens[i->first] = len;
		sum ^= N ^ len;
	}

//	printf("sum = %d\n", sum);
	if (sum == 0) {
		printf("SECOND\n");
	} else {
		printf("FIRST\n");
		int need = 1;
		while ((need << 1) <= sum) need <<= 1;

		int vfree = 0, vprv = 0;
		repi(it, vlens) {
			int i = it->first;
			if (i != vprv + 1) vfree = vprv + 1;
			vprv = i;
			int len = it->second;
			if (len & need) {
				int res = len ^ sum;
				int curlen = 0, cnt = 0, prv = 0;
				int ind;
				if (res) {
					repi(j, vcuts[i]) {
						int cur = j->first;
						if (cnt == 0) {
							if (curlen + cur - prv >= res) break;
							else curlen += cur - prv;
						}
						cnt += j->second;
						prv = cur;
					}
					ind = prv + res - curlen;
				}
				else ind = 0;

				printf("%d %d %d %d\n", i, ind, i, M);
				return 0;
			}
		}

		if (vprv < N - 1) vfree = N - 1;
		if (vfree) {
			if (M & need) {
				int res = M ^ sum;
				printf("%d %d %d %d\n", vfree, res, vfree, M);
				return 0;
			}
		}

		int hfree = 0, hprv = 0;
		repi(it, hlens) {
			int i = it->first;
			if (i != hprv + 1) hfree = hprv + 1;
			int len = it->second;
			if (len & need) {
				int res = len ^ sum;
				int curlen = 0, cnt = 0, prv = 0;
				int ind;
				if (res) {
					repi(j, hcuts[i]) {
						int cur = j->first;
						if (cnt == 0) {
							if (curlen + cur - prv >= res) break;
							else curlen += cur - prv;
						}
						cnt += j->second;
						prv = cur;
					}
					ind = prv + res - curlen;
				} else ind = 0;

				printf("%d %d %d %d\n", ind, i, N, i);
				return 0;
			}
		}

		if (hprv < M - 1) hfree = M - 1;
		if (hfree) {
			if (N & need) {
				int res = N ^ sum;
				printf("%d %d %d %d\n", res, hfree, N, hfree);
				return 0;
			}
		}
	}

	return 0;
}