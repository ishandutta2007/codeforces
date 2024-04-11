#include <bits/stdc++.h>
using namespace std;
#define M 2000001
typedef long long INT;

int a[M], LEFT[M], RIGHT[M];

INT calc(int *c, int st, int en) {
//	a[st, st+1, ... , en-1];
	if (en <= st+1) return 0;
	int mid = (st + en) >> 1;
	INT rlt = calc(c, st, mid) + calc(c, mid, en);
	for (int i = st; i < mid; i ++) LEFT[i - st] = c[i];
	for (int i = mid; i < en; i ++) RIGHT[i - mid] = c[i];
	int i = 0, j = 0;
	for (int k = st; k < en; k ++) {
		if (i == mid - st) c[k] = RIGHT[j], j ++;
		else if (j == en - mid) c[k] = LEFT[i], i ++, rlt += j;
		else if (LEFT[i] <= RIGHT[j]) c[k] = LEFT[i], i ++, rlt += j;
		else c[k] = RIGHT[j], j ++;
	}
	return rlt;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++) a[i] = i;
    for(int i = 1; i * 2 <= n && i <= k; i ++) swap(a[i], a[n+1-i]);
    printf("%I64d\n", calc(a, 1, n + 1));
}