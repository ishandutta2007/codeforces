#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int expmod(int a, long long b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int rlt = expmod(a, b / 2);
	rlt = 1ll * rlt * rlt % P;
	if (b & 1) rlt = 1ll * rlt * a % P;
	return rlt;
}

int main() {
	int k, now = 2, you;
	long long x;
	int tag = 1;
	scanf("%d", &k);
	while (k --) {
		scanf("%I64d", &x);
		if (x % 2 == 0) tag = -1;
		now = expmod(now, x);
	}
	if (now % 2) now = (P + now) / 2;
	else now /= 2;
	you = now - tag;
    if (you % 3 == 0) you /= 3;
    else if (you % 3 == 1) you = (P + 1ll * you) / 3;
    else you = (P * 2 + 1ll * you) / 3;
	printf("%d/%d\n", you % P, now % P);
	return 0;
}