#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define check(a) cout << a << endl;
#define CHECK cout << "wow" << endl;
using namespace std;
typedef long long LL;
const int MAXN = 300005;
const int B = 300001;

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
set<int> S1[MAXN << 1], S2[MAXN << 1];

int Query1(int l, int r) {
	int sum = sum1[r] - sum1[l - 1];
	int need = sum / 2 + (sum > 0? 1 : -1);
	return *S1[B + sum1[l - 1] + need].lower_bound(l);
}

int Query2(int l, int r) {
	int sum = sum2[r] - sum2[l - 1];
	int need = sum / 2 + (sum > 0? 1 : -1);
	return *S2[B + sum2[l - 1] + need].lower_bound(l);
}

void solve() {
	read(n); read(q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		sum1[i] = (s[i] == '+'? 1 : -1);
		if (!(i & 1)) sum1[i] = -sum1[i];
		sum1[i] += sum1[i - 1];
		S1[B + sum1[i]].insert(i);
	}
	for (int i = 2; i <= n; ++i) {
		sum2[i] = (s[i] == '+'? 1 : -1);
		if (i & 1) sum2[i] = -sum2[i];
		sum2[i] += sum2[i - 1];
		S2[B + sum2[i]].insert(i);
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
				printf("2\n%d ", r);
				--r;
			}
			if (l & 1) printf("%d\n", Query1(l, r));
			else printf("%d\n", Query2(l, r));
		}
	}
	for (int i = 1; i <= n; ++i) {
		S1[B + sum1[i]].clear();
	}
	for (int i = 2; i <= n; ++i) {
		S2[B + sum2[i]].clear();
	}
}

int main() {
	int T; read(T);
	while (T--) {
		solve();
	}
	return 0;
}