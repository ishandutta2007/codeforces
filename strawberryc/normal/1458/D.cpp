#include <bits/stdc++.h>

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 5e5 + 5, E = 5e5, M = N << 1;

int n, sum[N], cnt[M];
char s[N];

void work()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1]
		+ (s[i] == '1' ? 1 : -1);
	for (int i = -n; i <= n; i++) cnt[i + E] = 0;
	for (int i = 1; i <= n; i++)
		cnt[(s[i] == '1' ? sum[i - 1] : sum[i]) + E]++;
	int L = 0, R = 0, cur = E;
	for (int i = 1; i <= n; i++) L = Min(L, sum[i]),
		R = Max(R, sum[i]);
	L += E; R += E;
	for (int i = 1; i <= n; i++)
		if (cur == L) putchar('1'),
			cnt[L]--, L += !cnt[L], cur++;
		else if (cur == R) putchar('0'),
			cnt[R - 1]--, R -= !cnt[R - 1], cur--;
		else if (cnt[cur - 1] > 1) cur--, cnt[cur]--, putchar('0');
		else cnt[cur]--, cur++, putchar('1');
	puts("");
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}