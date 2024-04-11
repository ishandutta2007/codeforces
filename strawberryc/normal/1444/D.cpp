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

const int N = 1005, M = N * N / 2;

int n, a[N], b[N], pa[N], pb[N], dx[N], dy[N];
std::bitset<M> f[N];

bool part(int *a, int *res)
{
	f[0].reset(); f[0][0] = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i];
	if (sum & 1) return 0; sum >>= 1;
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] | (f[i - 1] << a[i]);
	if (!f[n][sum]) return 0;
	for (int i = n; i >= 1; i--)
		if (f[i - 1][sum]) res[i] = -1;
		else res[i] = 1, sum -= a[i];
	return 1;
}

inline bool o(int x, int y) {return x > y;}

void work()
{
	int tn;
	read(tn);
	for (int i = 1; i <= tn; i++) read(a[i]);
	read(n);
	for (int i = 1; i <= n; i++) read(b[i]);
	if (tn != n) return (void) puts("No");
	if (!part(a, pa)) return (void) puts("No");
	if (!part(b, pb)) return (void) puts("No");
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++) cnt1 += pa[i] > 0, cnt2 += pb[i] > 0;
	if (cnt1 > cnt2)
	{
		for (int i = 1; i <= n; i++)
			pa[i] = -pa[i], pb[i] = -pb[i];
		cnt1 = n - cnt1; cnt2 = n - cnt2;
	}
	std::vector<int> posa, nega, posb, negb;
	for (int i = 1; i <= n; i++)
		(pa[i] > 0 ? posa : nega).push_back(a[i]),
			(pb[i] > 0 ? posb : negb).push_back(b[i]);
	std::sort(posa.begin(), posa.end(), o);
	std::sort(posb.begin(), posb.end());
	std::sort(nega.begin(), nega.end(), o);
	std::sort(negb.begin(), negb.end());
	for (int i = 1; i <= cnt1; i++) dx[i] = posa[i - 1], dy[i] = posb[i - 1];
	for (int i = cnt1 + 1; i <= cnt2; i++)
		dx[i] = -nega[i - cnt1 - 1], dy[i] = posb[i - 1];
	for (int i = cnt2 + 1; i <= n; i++)
		dx[i] = -nega[i - cnt1 - 1], dy[i] = -negb[i - cnt2 - 1];
	puts("Yes");
	for (int i = 1, x = 0, y = 0; i <= n; i++)
		printf("%d %d\n", x, y), x += dx[i],
		printf("%d %d\n", x, y), y += dy[i];
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}