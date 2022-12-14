#include <bits/stdc++.h>
using namespace std;

int n, k;

char s[5];

bool get_clue() {
	scanf("%s", s);
	if (!strcmp(s, "NIE")) return 0;
	return 1;
}

int myfind(int st, int en) {
    if (st == en) return st;
	int mid = (st + en) / 2;
	printf("1 %d %d\n", mid, mid + 1);
    fflush(stdout);
    bool clue = get_clue();
    if (clue) return myfind(st, mid);
    return myfind(mid + 1, en);
}

int main() {
	scanf("%d %d", &n, &k);
	int a = myfind(1, n), b;
	if (a == 1) b = myfind(a + 1, n);
	else if (a == n) b = myfind(1, a - 1);
	else {
		b = myfind(a + 1, n);
		printf("1 %d %d\n", b, a);
		fflush(stdout);
		if (!get_clue()) b = myfind(1, a - 1);
	}
	printf("2 %d %d\n", a, b);
	fflush(stdout);
	return 0;
}