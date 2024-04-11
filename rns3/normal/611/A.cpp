#include <bits/stdc++.h>
using namespace std;
#define M 100100

int main() {
	//freopen("GB2015_A2.in", "r", stdin);
	int x;
	char s[10];
	scanf("%d", &x);
	scanf("%s", s);	scanf("%s", s);
	if (s[0] == 'w') {
		assert(x>=1 && x<=7);
		printf("%d\n", 52 + (x == 6 || x == 5));
	} else {
		assert(x>=1 && x<=31);
		printf("%d\n", 12 - (x>29) - 4 * (x>30));
	}
	return 0;
}