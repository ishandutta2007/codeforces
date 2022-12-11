#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;

const int INF = 1e9;
const int MAXN = 100000;

int a[MAXN];
int b[MAXN];

void finish(char * s) {
	printf("%s", s);
	exit(0);
}

int main() {
	int n;
	cin >> n;
	FOR(i, n) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	int p = -1, q, pos;
	FOR(i, n) {
		if (a[i] != b[i]) {
			p = a[i];
			q = b[i];
			pos = i;
			break;
		}
	}
	if (p != -1) {
		for (int i = pos + 1; i < n; ++i) {
			if (a[i] != b[i] && (a[i] != q || b[i] != p))
				finish("NO");
		}
	}
	finish("YES");


	return 0;
}