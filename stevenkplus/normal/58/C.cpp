#include <cstdio>
#include <map>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
int N;
map<int, int> mymap;
int main() {
	scanf("%d", &N);
	int cur = 0;
	for(int i = 0; i < N; ++i) {
		if (i * 2 < N) {
			++cur;
		} else if (i * 2 > N) {
			--cur;
		}
		int nxt;
		scanf("%d", &nxt);
		int diff = nxt - cur;
		if (diff >= 0)
			++mymap[diff];
	}

	int m = 0;
	repi(i, mymap) {
		if (i->second > m) {
			m = i->second;
		}
	}

	int ans = N - m;
	printf("%d\n", ans);
	return 0;
}