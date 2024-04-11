#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mymap;
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _i; ++i)

int N;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		++mymap[tmp];
	}

	int ans = 0;
	repi(i, mymap) {
		if (i->first == 0) continue;
		if (i->second == 2) {
			++ans;
		} else if (i->second > 2) {
			ans = -1;
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}