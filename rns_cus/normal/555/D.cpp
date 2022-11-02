#include <cstdio>
#include <algorithm>

#define N 200100

using namespace std;

#define gc getchar
#define pc putchar

typedef __int64 LL;

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

int n, m;
int x[N];
int id[N], rid[N];

bool cmp(int a, int b) { return x[a] < x[b]; }

main() {
//	freopen("2.in", "r", stdin);
//	freopen("2.ans", "w", stdout);
	n = getint();
	m = getint();
	for (int i = 0; i < n; i ++) x[i] = getint(), id[i] = i;
	sort(id, id + n, cmp);
	for (int i = 0; i < n; i ++) rid[id[i]] = i;
	sort(x, x + n);
	while (m --) {
		int a = getint();
		int l = getint();
		a --;
		a = rid[a];
        while (l) {
        	int p1 = upper_bound(x + a, x + n, x[a] + l) - x - 1;
			l -= x[p1] - x[a];
			if (l == 0) {
				a = p1;
				break;
			}
			int p2 = lower_bound(x, x + p1, x[p1] - l) - x;
			l -= x[p1] - x[p2];
			if (l == 0) {
				a = p2;
				break;
			}
			if (a == p2) {
				if (a == p1) break;
				else {
					int len = x[p1] - x[a];
					int r = l % ((LL)len << 1);
					if (r >= len) {
						a = p1;
						l = r - len;
					} else l = r;
				}
			} else a = p2;
        }
		putint(id[a] + 1);
		puts("");
	}
}