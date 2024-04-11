#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;

vector<int> conn[MAXN];

double sum = 0;

void go(int cur, int prv, int depth) {
	sum += 1. / depth;
	repi(i, conn[cur]) {
		int nxt = *i;
		if (nxt != prv) {
			go(nxt, cur, depth + 1);
		}
	}
}

int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	go(1, 0, 1);
	printf("%.10f\n", sum);

	return 0;
}