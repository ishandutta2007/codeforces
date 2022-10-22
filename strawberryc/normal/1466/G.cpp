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

typedef long long ll;

const int N = 1e5 + 5, M = 1e6 + 5, L = 2e6 + 5, EI = 1e9 + 7;

int n, q, len[N], D, lo, cnt[N][26], k[M], EI1, EI2, p1[L], p2[L],
f1[L], f2[L], ans[M], l[M], lsum[M], pow2[N];
char s[L], t[N], o[M], w[M];
ll le[M], ri[M];
std::map<ll, int> occ;

void generator(int &EI)
{
	while (1)
	{
		EI = ((1ll * rand() << 15) | rand()) % 100000000 + 900000000;
		int S = sqrt(EI); bool pr = 1;
		for (int i = 2; i <= S; i++)
			if (EI % i == 0) {pr = 0; break;}
		if (pr) return;
	}
}

ll getHash(int l, int r)
{
	if (l > r) return 0;
	int h1 = (f1[r] - 1ll * f1[l - 1] * p1[r - l + 1] % EI1 + EI1) % EI1,
		h2 = (f2[r] - 1ll * f2[l - 1] * p2[r - l + 1] % EI2 + EI2) % EI2;
	return 1ll * h1 * EI2 + h2;
}

ll getPrefix(int th, int i) {return i ? le[lsum[th - 1] + i] : 0;}

ll getSuffix(int th, int i) {return i <= l[th] ? ri[lsum[th - 1] + i] : 0;}

int main()
{
	generator(EI1); generator(EI2);
	read(n); read(q);
	scanf("%s", s + 1); len[0] = strlen(s + 1);
	scanf("%s", t + 1);
	for (int i = n + 1; i <= 1145; i++) t[i] = 'a';
	pow2[0] = 1;
	for (int i = 1; i <= n; i++) pow2[i] = 2ll * pow2[i - 1] % EI;
	for (D = 0; len[D] <= 1000000; D++)
	{
		len[D + 1] = len[D] * 2 + 1;
		for (int i = 1; i <= len[D]; i++) s[i + len[D] + 1] = s[i];
		s[len[D] + 1] = t[D + 1];
	}
	for (int i = D + 1; i <= n; i++)
	{
		for (int c = 0; c < 26; c++)
			cnt[i][c] = (cnt[i - 1][c] << 1) % EI;
		cnt[i][t[i] - 'a'] = (cnt[i][t[i] - 'a'] + 1) % EI;
	}
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= len[D]; i++)
	{
		p1[i] = 31ll * p1[i - 1] % EI1; p2[i] = 37ll * p2[i - 1] % EI2;
		f1[i] = (31ll * f1[i - 1] + s[i] - 'a' + 1) % EI1;
		f2[i] = (37ll * f2[i - 1] + s[i] - 'a' + 1) % EI2;
	}
	for (int i = 1; i <= len[0]; i++)
		for (int j = i; j <= len[0]; j++)
			occ[getHash(i, j)]++;
	for (int i = 1; i <= q; i++)
	{
		read(k[i]); scanf("%s", o + 1); lo = strlen(o + 1);
		l[i] = lo; lsum[i] = lsum[i - 1] + l[i];
		for (int j = 1, h1 = 0, h2 = 0; j <= lo; j++)
		{
			h1 = (31ll * h1 + o[j] - 'a' + 1) % EI1;
			h2 = (37ll * h2 + o[j] - 'a' + 1) % EI2;
			le[lsum[i - 1] + j] = 1ll * h1 * EI2 + h2;
			w[lsum[i - 1] + j] = o[j];
		}
		for (int j = lo, h1 = 0, h2 = 0; j >= 1; j--)
		{
			h1 = (1ll * (o[j] - 'a' + 1) * p1[lo - j] + h1) % EI1;
			h2 = (1ll * (o[j] - 'a' + 1) * p2[lo - j] + h2) % EI2;
			ri[lsum[i - 1] + j] = 1ll * h1 * EI2 + h2;
		}
		ans[i] = occ[getPrefix(i, lo)];
	}
	for (int z = 1; z <= D; z++)
	{
		for (int i = 1; i <= q; i++) if (z <= k[i])
		{
			ans[i] *= 2;
			for (int j = 1; j <= l[i]; j++) if (w[lsum[i - 1] + j] == t[z]
				&& j - 1 <= len[z - 1] && l[i] - j <= len[z - 1]
				&& getPrefix(i, j - 1) ==
					getHash(len[z - 1] - j + 2, len[z - 1])
				&& getSuffix(i, j + 1) ==
					getHash(1, l[i] - j))
						ans[i]++;
		}
	}
	for (int i = 1; i <= q; i++) if (k[i] > D)
	{
		ans[i] = 1ll * ans[i] * pow2[k[i] - D] % EI;
		for (int j = 1; j <= l[i]; j++) if (getPrefix(i, j - 1)
			== getHash(len[D] - j + 2, len[D]) && getSuffix(i, j + 1)
			== getHash(1, l[i] - j))
			ans[i] = (cnt[k[i]][w[lsum[i - 1] + j] - 'a'] + ans[i]) % EI;
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}