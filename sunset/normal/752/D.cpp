#include <bits/stdc++.h>
#define N_MAX 100000
typedef long long lnt;
typedef char cnt;
typedef void vac;
const lnt BAS = 233, MOD = 1004535809;
int n, m, i, j, w;
lnt g, h, ans, res;
cnt s[N_MAX + 1];
std::map<lnt, std::vector<lnt> > M;
std::map<lnt, lnt> F;
int main()
{
	scanf("%d %d", &n, &m);
	for  (i = 0; i < n; ++i)
	{
		scanf("\n%s %d", s, &w);
		h = 0;
		for (j = 0; j < m; ++j)
			h = (h * BAS + s[j]) % MOD;
		M[h].push_back(w);
		g = 0;
		for (j = m - 1; j >= 0; --j)
			g = (g * BAS + s[j]) % MOD;
		F[h] = g;
	}
	for (std::map<lnt, std::vector<lnt> >::iterator i = M.begin(); i != M.end(); ++i)
		std::sort(i->second.begin(), i->second.end(), std::greater<lnt>());
	for (std::map<lnt, std::vector<lnt> >::iterator i = M.begin(); i != M.end(); ++i)
	{
		h = i->first;
		std::vector<lnt> & V = i->second;
		if (h == F[h])
		{
			for (std::vector<lnt>::iterator j = V.begin(); j < V.end() && *j > 0; j += 2)
				if (j + 1 < V.end())
				{
					if (*(j + 1) > 0)
						ans += *j + *(j + 1);
					else if (*j + *(j + 1) > 0)
						ans += *j + *(j + 1), res = std::max(res, -*(j + 1));
					else res = std::max(res, *j);
				}
				else res = std::max(res, *j);
		}
		else if (h < F[h])
		{
			std::vector<lnt> & U = M[F[h]];
			for (std::vector<lnt>::iterator j = U.begin(), k = V.begin(); j != U.end() && k != V.end(); ++j, ++k)
				if (*j + *k > 0)
					ans += *j + *k;
				else break;
		}
	}
	printf("%I64d\n", ans + res);
	return 0;
}