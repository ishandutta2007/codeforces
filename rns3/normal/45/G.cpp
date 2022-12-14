#include <bits/stdc++.h>
using namespace std;
#define M 20000000

int n, m;
int p[M/5], cnt;
bool flag[M];

void prepare() {
	flag[1] = 1;
    for (int i = 2; i <= m; i++) {
        if (!flag[i]) {
            p[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * p[j] <= m; j++) {
            flag[i * p[j]] = 1;
            if (i % p[j] == 0) {
                break;
            }
        }
    }
}

int main() {
   // freopen("45G1.in", "r", stdin);
    scanf("%d", &n);
    if (n == 2) {
    	puts("1 1");
		return 0;
    }
    m = n * (n + 1) / 2;

    prepare();
    for (int i = 1; i <= n; i++) if (!flag[i] && !flag[m-i]) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", j == i ? 1 : 2);
		}
		puts("");
		return 0;
    }

	for (int i = 4; i <= n; i++) if (!flag[i] && !flag[m - 3 - i]) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", j == 3 ? 2 : j == i ? 3 : 1);
		}
		return 0;
	}
    return 0;
}