#include <cstdio>

#include <map>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;

int N;

map<int, int> mymap;
int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		int nxt;

		scanf("%d", &nxt);
		++mymap[nxt];
	}

	int big = 0;
	int my = 0;
	repi(i, mymap) {
		if (i->second / 2)
		mymap[i->first + 1] += i->second / 2;
		i->second %= 2;
		if (i->second) ++my;
		if (i->first > big) big = i->first;
	}

	printf("%d\n", 1 + big - my);
	return 0;
}