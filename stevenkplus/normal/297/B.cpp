#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

#define dwni(i, a) for(typeof((a).rbegin()) i = (a).rbegin(), _##i = (a).rend(); i != _##i; ++i)

map<int, int> mymap;
int N, M, K;

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; ++i) {
		int a; scanf("%d", &a);
		++mymap[a];
	}
	for(int i = 0; i < M; ++i) {
		int a; scanf("%d", &a);
		--mymap[a];
	}

	int sum = 0;
	dwni(i, mymap) {
		sum += i->second;
		if (sum > 0) break;
	}

	if (sum > 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}