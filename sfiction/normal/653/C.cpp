#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 15E4 + 10, MAXA = 15E4 + 10;

int n;
int a[MAXN];
int b[MAXN], B;
int cnt[MAXN], val[MAXN];

int odd[3][MAXA];
int even[3][MAXA];

int ans1, ans2;

bool good(int i){
	return i & 1 ? a[i] < a[i + 1] : a[i] > a[i + 1];
}

void check(int i, int j){
	if (cnt[i] + cnt[j] < B)
		return;

//	printf("check %d %d\n", i, j);

	swap(a[i], a[j]);
	bool flag = good(i - 1) && good(i) && good(j - 1) && good(j);
	swap(a[i], a[j]);

	ans1 += flag;
	if (cnt[j])
		ans2 += flag;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[0] = MAXA;
	a[n + 1] = n & 1 ? MAXA : 0;
	B = n + 1;
	for (int i = 0; i <= n; ++i)
		B -= b[i] = (i & 1 ? a[i] < a[i + 1] : a[i] > a[i + 1]);

	if (B > 4){
		puts("0");
		return 0;
	}

	// 1. adjacent
	for (int i = 1; i < n; ++i)
		if (3 - (b[i - 1] + b[i] + b[i + 1]) == B){
			if (i & 1)
				ans1 += a[i - 1] > a[i + 1] && a[i + 1] < a[i] && a[i] > a[i + 2];
			else
				ans1 += a[i - 1] < a[i + 1] && a[i + 1] > a[i] && a[i] < a[i + 2];
		}

	// 2. not adjacent
	for (int i = 1; i <= n; ++i){
		cnt[i] = 2 - (b[i - 1] + b[i]);
		if (i & 1)
			val[i] = min(a[i - 1], a[i + 1]);
		else
			val[i] = max(a[i - 1], a[i + 1]);
	}

	for (int i = 1; i <= n; ++i)
		if (cnt[i]){
			for (int j = 1; j < i - 1; ++j)
				check(i, j);
			for (int j = i + 2; j <= n; ++j)
				check(i, j);
//			printf("%d %d %d %d\n", i, cnt[i], ans1, ans2);
		}
	printf("%d\n", ans1 - ans2 / 2);
	return 0;
}