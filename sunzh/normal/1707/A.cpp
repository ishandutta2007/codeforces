#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)

const int N = 1e5 + 5;

int a[N];
char s[N];

void go () {
	int n, q;
	scanf("%d%d", &n, &q);
	FOR(i, 1, n) {
		scanf("%d", a + i);
		if (a[i] > n) a[i] = n;
	}
	if (q >= n) {
		FOR(i, 1, n) putchar('1');
		putchar('\n');
		return;
	}
	// q < n
	int pos = 1;
	s[n + 1] = 0;
	s[n] = '1';
	ROF(i, n - 1, 1) {
		s[i] = '0';
		if (a[i] > q) {
			++pos;
			if (pos <= q) {
				s[i] = '1';
			}
		} else {
			s[i] = '1';
			if (a[i] > pos) {
				++pos;
			}
			// if (pos < a[i]) pos = a[i];
		}
	}
	printf("%s\n", s + 1);
}

int main () {
	int t;
	scanf("%d", &t);
	FOR(_, 1, t) go();
	return 0;
}