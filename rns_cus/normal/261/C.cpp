#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define N 100100

LL f[50][N];

LL calc(int t, LL y) {
	LL x = 1LL << t;
	if(y > x) return 0;
	if(t == 0) return 1;
	if(y < N && f[t][y] >= 0) return f[t][y];
    LL rt = calc(t - 1, y);
    if(!(y & 1)) rt += calc(t - 1, y >> 1);
    if(y < N) f[t][y] = rt;
    return rt;
}

LL oo(LL x, LL y) {
	if(!x) return 0;
	int j = 0;
	while((1LL << j) <= x) j ++;
	j --;
	LL rt = calc(j, y);
	if(y % 2 == 0) rt += oo(x - (1LL << j), y >> 1);
	return rt;
}

LL run(LL x, LL y) {
    if(!y) return 0;
	LL rt = 0;
	for(int i = 0; ; i ++) {
		if((1LL << i) <= x) {
			rt += calc(i, y);
			x -= (1LL << i);
		} else {
			rt += oo(x, y);
			break;
		}
	}
	return rt;
}

int main() {
	memset(f, -1, sizeof(f));
	LL n, t;
	scanf("%I64d %I64d\n", &n, &t);
	LL rt = run(n + 1, t);
	if(t == 1) rt --;
	printf("%I64d\n", rt);
	return 0;
}