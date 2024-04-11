#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define check(a) cout << a << endl;
#define CHECK cout << "wow" << endl;
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

char s[MAXN];
int n, q, sum1[MAXN], sum2[MAXN];

void solve() {
	read(n); read(q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		sum1[i] = (s[i] == '+'? 1 : -1);
		if (!(i & 1)) sum1[i] = -sum1[i];
		sum1[i] += sum1[i - 1];
	}
	for (int i = 2; i <= n; ++i) {
		sum2[i] = (s[i] == '+'? 1 : -1);
		if (i & 1) sum2[i] = -sum2[i];
		sum2[i] += sum2[i - 1];
	}
	while (q--) {
		int l, r, sum;
		read(l); read(r);
		if (l & 1) {
			sum = sum1[r] - sum1[l - 1];
		} else {
			sum = sum2[r] - sum2[l - 1];
		}
		if (!sum) {
			printf("0\n");
		} else {
			if ((r - l + 1) & 1) {
				printf("1\n");
			} else {
				printf("2\n");
			}
		}
	}
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}