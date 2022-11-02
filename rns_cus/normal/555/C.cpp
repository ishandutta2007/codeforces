#include <cstdio>
#include <algorithm>

#include <set>
#include <map>

using namespace std;

typedef pair <int, bool> PII;

set <PII> S;
map <int, int> M;

#define gc getchar
#define pc putchar

int getint() {
	unsigned int c;
	int x = 0;
	while ((c = gc()) - '0' >= 10) if (c == '-') return -getint();
	do x = (x << 3) + (x << 1) + (c - '0'); while (((c = gc()) - '0') < 10);
	return x;
}

void putint(int n) {
	int i = 16, a[i];
	if (n < 0) pc('-');
	do {
		a[-- i] = 48 + abs(n % 10);
		n /= 10;
	} while (n);
	while (i < 16) pc(a[i ++]);
}

main() {
//	freopen("C.in", "r", stdin);
	int n = getint();
	int q = getint();
	while (q --) {
		int x = getint();
		int y = getint();
		char c;
		while (1) {
			c = getchar();
			if (c != ' ') break;
		}
		int rlt;
		set <PII>::iterator it = S.lower_bound(PII(x, 0));
		if (it != S.end() && it->first == x) {
			puts("0");
			continue;
		}
		if (c == 'U') {
			if (it == S.end()) rlt = y;
			else {
				if (it->second == 0) {	// 'L'
					int xx = it->first;
					int yy = n + 1 - xx;
					rlt = y - yy;
				} else {
					int xx = it->first;
					int yy = n + 1 - xx;
					rlt = M[xx] + y - yy;
				}
			}
		} else {
			if (it == S.begin()) rlt = x;
			else {
				it --;
				if (it->second == 1) {
					int xx = it->first;
					int yy = n + 1 - xx;
					rlt = x - xx;
				} else {
					int xx = it->first;
					int yy = n + 1 - xx;
					rlt = M[xx] + x - xx;
				}
			}
		}
		S.insert(PII(x, c == 'U'));
		M[x] = rlt;
		printf("%d\n", rlt);
	}
}