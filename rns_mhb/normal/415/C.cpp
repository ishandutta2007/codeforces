#include <bits/stdc++.h>
using namespace std;

int n, k, res;

int main() {
    scanf("%d%d", &n, &k);
    if (n == 1) {
        if (!k) puts("1");
		else puts("-1");
		return 0;
    }
    if (k >= n / 2) {
        res = k - n / 2;
        if(!res) for (int i = 1; i <= n; i ++) printf("%d ", i);
        else {
            res ++;
			printf("%d %d ", res, res * 2);
			for (int i = res * 2 + 1; i <= res * 2 + n - 2; i ++) printf("%d ", i);
        }
    }
    else puts("-1");
}