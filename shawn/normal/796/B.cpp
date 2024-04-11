#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int n, m, k, pos;
bool hole[1000010];

int main() {
	n = rd(), m = rd(), k = rd();
	pos = 1;
	for (int i = 1; i <= m; i ++) hole[rd()] = 1;
	if (hole[1]) return puts("1"), 0;
	for (int i = 1; i <= k; i ++) {
		int u = rd(), v = rd();
		if (hole[pos]) return printf("%d", pos), 0;
		if (pos == u) pos = v;
		else if (pos == v) pos = u;
	//	printf("%d\n", pos);
	}
	printf("%d", pos);
	return 0;
}