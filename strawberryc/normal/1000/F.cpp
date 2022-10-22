#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 5e5 + 5, SQ = 1005;

int n, S, T, a[N], maxa, m, cnt[N], in[N], col[N], ccnt[SQ], ans[N];

struct node
{
	int l, r, id, bl;
} que[N];

inline bool comp(const node &a, const node &b)
{
	return a.bl < b.bl || (a.bl == b.bl && a.r < b.r);
}

int main()
{
	int i, j, k, l = 1, r = 0;
	n = read();
	S = sqrt(n);
	For (i, 1, n) maxa = Max(maxa, a[i] = read());
	T = sqrt(maxa);
	For (i, 1, maxa) in[i] = (i - 1) / T + 1;
	m = read();
	For (i, 1, m)
		que[i].l = read(), que[i].r = read(), que[i].id = i,
		que[i].bl = (que[i].l - 1) / S + 1;
	std::sort(que + 1, que + m + 1, comp);
	For (i, 1, m)
	{
		int tl = que[i].l, tr = que[i].r;
		while (r < tr)
		{
			cnt[a[++r]]++;
			if (cnt[a[r]] == 1) ccnt[in[a[r]]]++;
			else if (cnt[a[r]] == 2) ccnt[in[a[r]]]--;
		}
		while (l > tl)
		{
			cnt[a[--l]]++;
			if (cnt[a[l]] == 1) ccnt[in[a[l]]]++;
			else if (cnt[a[l]] == 2) ccnt[in[a[l]]]--;
		}
		while (r > tr)
		{
			cnt[a[r--]]--;
			if (!cnt[a[r + 1]]) ccnt[in[a[r + 1]]]--;
			else if (cnt[a[r + 1]] == 1) ccnt[in[a[r + 1]]]++;
		}
		while (l < tl)
		{
			cnt[a[l++]]--;
			if (!cnt[a[l - 1]]) ccnt[in[a[l - 1]]]--;
			else if (cnt[a[l - 1]] == 1) ccnt[in[a[l - 1]]]++;
		}
		For (j, 1, in[maxa])
			if (ccnt[j])
			{
				int L = (j - 1) * T + 1, R = Min(j * T, maxa);
				For (k, L, R)
					if (cnt[k] == 1)
					{
						ans[que[i].id] = k;
						break;
					}
				break;
			}
	}
	For (i, 1, m) printf("%d\n", ans[i]);
	return 0;
}