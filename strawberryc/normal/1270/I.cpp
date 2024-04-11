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
typedef std::vector<std::pair<int, int> > vp;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;

const int N = 520;

int k, t, ans;
vl emp;
vvl a;
vp op;

vvl trans(vvl a, vp op)
{
	int n = a.size();
	vvl res;
	for (int i = 0; i < n; i++)
	{
		res.push_back(emp);
		for (int j = 0; j < n; j++)
		{
			res[i].push_back(0);
			for (int k = 0; k < t; k++)
				res[i][j] ^= a[i - op[k].first + n & n - 1]
					[j - op[k].second + n & n - 1];
		}
	}
	return res;
}

void jjd(vvl a, vp op)
{
	if (a.size() == 1) return (void) (ans += (a[0][0] > 0));
	a = trans(a, op); int n = a.size();
	vvl b[2][2];
	for (int i = 0; i < n; i++)
	{
		b[i & 1][0].push_back(emp); b[i & 1][1].push_back(emp);
		for (int j = 0; j < n; j++)
			b[i & 1][j & 1][i >> 1].push_back(a[i][j]);
	}
	for (int i = 0; i < t; i++) op[i].first &= (n >> 1) - 1,
		op[i].second &= (n >> 1) - 1;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		jjd(b[i][j], op);
}

int main()
{
	read(k); ll x; int u, v;
	for (int i = 0; i < (1 << k); i++)
	{
		a.push_back(emp);
		for (int j = 0; j < (1 << k); j++)
			read(x), a[i].push_back(x);
	}
	read(t);
	for (int i = 1; i <= t; i++)
		read(u), read(v), op.push_back(std::make_pair(u - 1, v - 1));
	return std::cout << (jjd(a, op), ans) << std::endl, 0;
}