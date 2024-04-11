#include <bits/stdc++.h>
using namespace std;

#define N (1 << 21)

long long total[22], sum[22];
int n, m, q, arr[N], tmp[N];

void mer(int a, int b, int depth) {
    if (a >= b) {
		sum[depth] = 0;
		return;
    }
    int mid = (a + b) >> 1;
    mer(a, mid, depth - 1);
    mer(mid + 1, b, depth - 1);
    int i = a, j = mid + 1, t = a, pp = a, ss = arr[a];
    total[depth] += 1LL * (b - a + 1) / 2 * (b - a + 1) / 2;
    while(i <= mid && j <= b) {
        if (arr[i] <= arr[j]) {
			if (ss != arr[i]) {
				ss = arr[i];
				pp = i;
			}
			tmp[t ++] = arr[i ++];
        }
        else {
			if (arr[j] == ss) total[depth] -= (i - pp);
			else {
                ss = arr[i];
                pp = i;
			}
			sum[depth] += mid - i + 1;
            tmp[t ++] = arr[j ++];
        }
    }
    while (i <= mid) tmp[t ++] = arr[i ++];
	while (j <= b) {
		if (arr[j] == ss) total[depth] -= (i - pp);
		tmp[t ++] = arr[j ++];
	}
    for (int i = a; i <= b; i ++) arr[i] = tmp[i];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i ++) scanf("%d", &arr[i]);
    mer(0, (1 << n) - 1, n);
	scanf("%d", &m);
	while (m --) {
		scanf("%d", &q);
        for (int i = 1; i <= q; i ++) sum[i] = total[i] - sum[i];
        long long ans = 0;
        for (int i = 1; i <= n; i ++) ans += sum[i];
        printf("%I64d\n", ans);
	}
}