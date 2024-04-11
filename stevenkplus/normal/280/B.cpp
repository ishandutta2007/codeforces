#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef set<pii>::iterator IT;

const int MAXN = 100100;

set<pii> myset;
int N;
pii ar[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ar[i] = pii(tmp, i);
	}

	int ans = 0;
	sort(ar, ar + N);
	for(int i = N; i > 0; --i) {
		pii cur = ar[i - 1];

		pii sw = pii(cur.second, cur.first);
		myset.insert(sw);
		IT it = myset.find(sw);
		if (it != myset.begin()) {
			--it;
			int val = it->second;
			int sum = val ^ cur.first;
//			printf("Checking %d ^ %d\n", val, cur.first);
			ans = max(ans, sum);

			++it;
		}
		++it;
		if (it != myset.end()) {
			int val = it->second;
			int sum = val ^ cur.first;
//			printf("Checking %d ^ %d\n", val, cur.first);
			ans = max(ans, sum);
		}
	}

	printf("%d\n", ans);
	return 0;
}