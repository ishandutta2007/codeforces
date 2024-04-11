#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll infl = 1LL << 60;
const int MAXN = 10;

ll m = infl;
ll ar[MAXN];
char ops[MAXN];
bool used[MAXN];

ll go(int aa, int bb, int op) {
	ll a = ar[aa];
	ll b = ar[bb];
	if (ops[op] == '+') {
		return a + b;
	} else {
		return a * b;
	}
}

void rec(int num, int op) {
	if (num == 1) {
		for(int i = 0; i < 4; ++i) {
			if (!used[i]) {
				m = min(m, ar[i]);
			}
		}
		return;
	}

	for(int i = 0; i < 4; ++i) {
		if (!used[i]) {
			for(int j = i + 1; j < 4; ++j) {
				if (!used[j]) {
					ll res = go(i, j, op);
					ll tmp = ar[i];
					used[j] = true;
					ar[i] = res;
					rec(num - 1, op + 1);
					ar[i] = tmp;
					used[j] = false;
				}
			}
		}
	}
}

int main() {
	for(int i = 0; i < 4; ++i) {
		scanf("%I64d", ar + i);
	}

	for(int i = 0; i < 3; ++i) {
		scanf(" %c", ops + i);
	}

	rec(4, 0);

	printf("%I64d\n", m);
	return 0;
}