#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define check(a) cout << a << endl;
#define CHECK cout << "wow" << endl;
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

char s[100];
int k, cnt[10], ans1, ans2;

bool Check(int x) {
	if (!x) return 0;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return 1;
	}
	return 0;
}

void DFS(int p, int num, int c) {
	if (p > k) {
		if (Check(num)) {
			if (c < ans1) {
				ans1 = c; ans2 = num;
			}
		}
		return;
	}
	DFS(p + 1, num, c);
	DFS(p + 1, num * 10 + s[p] - '0', c + 1);
}

void solve() {
	mset(cnt, 0);
	read(k);
	scanf("%s", s + 1);
	for (int i = 1; i <= k; ++i) {
		++cnt[s[i] - '0'];
	}
	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] && (i == 1 || i == 4 || i == 6 || i == 8 || i == 9)) {
			printf("1\n%d\n", i);
			return;
		}
	}
	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] > 1 && (i == 2 || i == 3 || i == 5 || i == 7)) {
			printf("2\n%d%d\n", i, i);
			return;
		}
	}
	ans1 = k + 1;
	DFS(1, 0, 0);
	printf("%d\n%d\n", ans1, ans2);
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}