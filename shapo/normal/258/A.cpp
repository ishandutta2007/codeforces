#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define maxn 100500

using namespace std;

char s[maxn];
int n;
int sum[maxn];

inline bool is_0 (int l, int r) {
	return (sum[r] - sum[l - 1] == 0);
}

inline bool is_1 (int l, int r) {
	return (sum[r] - sum[l - 1] == r - l + 1);
}

int len_eq (int x, int y) {
	int l = 0, r = y - x + 2;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (!is_0(x, x + m) && !is_1(x, x + m))
			r = m;
		else
			l = m;
	}
	return l;
}

bool cmp (int l, int r) {
	int ln = len_eq (l, r - 1);
	if (ln == r - l) return false;
	return (s[l + ln] < s[l + ln + 1]);
}

int main () {
	scanf (" %s", s);
	n = strlen (s);
	for (int i = 0; i < n; ++i)
		sum[i + 1] = sum[i] + (s[i] - '0');
	int ans = 0;
	while (ans < n && s[ans] != '0')++ans;
	ans = min (ans, n - 1);
	s[ans] = 0;
	//printf ("ans = %d\n", ans);
	if (ans) printf("%s", s);
	if (ans != n - 1) printf("%s", s + ans + 1);
	printf ("\n");
	return 0;
}