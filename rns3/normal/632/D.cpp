#include <bits/stdc++.h>
using namespace std;
#define M 1001001

int n, MX;
int number[M], cnt[M];
int a[M];
int LCM, len;

int main() {
	///freopen("D2.in", "r", stdin);
	scanf("%d %d", &n, &MX);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] <= MX) {
			number[a[i]]++;
		}
	}
	for (int i = 1; i <= MX; i++) {
		for (int j = i; j <= MX; j += i) {
			cnt[j] += number[i];
		}
	}
	for (int i = 1; i <= MX; i++) {
		if (cnt[i] > len) {
			len = cnt[i];
			LCM = i;
		}
	}
	if (!LCM) {
		LCM = 1;
	}
	printf("%d %d\n", LCM, len);
	for (int i = 1; i <= n; i++) if (LCM % a[i] == 0) {
		printf("%d ", i);
	}
	puts("");
	return 0;
}