#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 100100;

map<int, int> front;
map<int, int> back;

int N;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		front[a]++;
		if (a != b) {
			back[b]++;
		}
	}
	int need = (N + 1) / 2;
	int m = N + 1;
	repi(i, front) {
		int b = back[i->first];
		int f = i->second;
		int bb = need - f;
		if (b >= bb) {
			m = min(m, bb);
		}
	}
	repi(i, back) {
		int b = i-> second;
		int f = front[i->first];
		int bb = need - f;
		if (b >= bb) {
			m = min(m, bb);
		}
	}
	if (m < 0) {
		m = 0;
	}
	if (m > N) {
		m = -1;
	}
	printf("%d\n", m);
	return 0;
}