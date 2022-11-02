#include <bits/stdc++.h>
using namespace std;
#define N 505050

int n, m, k, p[N];
char s[N], t[N];

void prepare() {
    p[1] = 0;
    for(int i = 2, k = 0; i <= m; i ++){
        while(k > 0 && t[k + 1] != t[i]) k = p[k];
        if(t[k + 1] == t[i]) k ++;
        p[i] = k;
    }
}

int a[N], b[N];

void func1() {
    for (int i = 1, j = 0; i <= n; i ++) {
		while (j > 0 && t[j+1] != s[i]) j = p[j];
		if (t[j+1] == s[i]) j ++;
		if (i >= k) {
			int tmp = j;
			while (!a[tmp]) {
				a[tmp] = i;
				tmp = p[tmp];
			}
		}
		if (j == m) a[m] = i;
    }
}

void func2() {
	for (int i = n, j = 0; i >= 1; i --) {
		while (j > 0 && t[j+1] != s[i]) j = p[j];
		if (t[j+1] == s[i]) j ++;
		if (i <= n - k + 1) {
			int tmp = j;
			while (!b[tmp]) {
				b[tmp] = i;
				tmp = p[tmp];
			}
		}
	}
}

int main() {
	scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
	prepare();
	func1();
	for (int i = 1; i <= (m >> 1); i ++) swap(t[i], t[m+1-i]);
	prepare();
	func2();
	bool flag = 0;
	if (a[m]) {
		if (a[m] <= 2 * k) {
			flag = 1;
			puts("Yes");
			printf("%d %d\n", 1, k + 1);
			return 0;
		}
		else {
			puts("Yes");
			printf("%d %d\n", a[m] - 2 * k + 1, a[m] - k + 1);
			return 0;
		}
	}
	int up = min(k, m - 1);
	for (int i = max(1, m - k); i <= up; i ++) {
		if (a[i] >= k && b[m-i] && b[m-i] <= n - k + 1 && a[i] < b[m-i]) {
			flag = 1;
			puts("Yes");
			printf("%d %d\n", a[i] - k + 1, b[m-i]);
			return 0;
		}
	}
	puts("No");
}