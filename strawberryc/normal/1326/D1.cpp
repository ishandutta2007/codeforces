#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1e6 + 5, M = N << 1;

int n, m, R[M];
char s[N], t[M];

bool judge(int l, int r)
{
	return R[l + r] >= r - l + 2;
}

void work()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	int l = 1, r = n, mxl = 0;
	while (l < r && s[l] == s[r]) l++, r--;
	t[0] = '!'; m = 0;
	for (int i = 1; i <= n; i++) t[++m] = '^', t[++m] = s[i];
	t[++m] = '^'; t[m + 1] = '@';
	int mx = 0, id = 0;
	for (int i = 1; i <= m; i++)
	{
		R[i] = mx > i ? std::min(R[(id << 1) - i], mx - i) : 1;
		while (t[i + R[i]] == t[i - R[i]]) R[i]++;
		if (i + R[i] > mx) mx = i + R[i], id = i;
	}
	for (int i = l; i <= r; i++)
	{
		if (judge(l, i) && i - l + 1 > mxl) mxl = i - l + 1;
		if (judge(i, r) && r - i + 1 > mxl) mxl = r - i + 1;
	}
	for (int i = 1; i < l; i++) putchar(s[i]);
	if (mxl)
	{
		if (judge(l, l + mxl - 1)) for (int i = l; i < l + mxl; i++) putchar(s[i]);
		else for (int i = r - mxl + 1; i <= r; i++) putchar(s[i]);
	}
	for (int i = r + 1; i <= n; i++) putchar(s[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}