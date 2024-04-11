#include <iostream>
#include <set>
#include <cassert>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 200011;
typedef long long intl;

struct Frac
{
	intl n, d;
	Frac(intl n, intl d) : n(n), d(d) { }
	bool operator <(const Frac &rhs) const
	{
		return (intl)n * rhs.d < (intl)d * rhs.n;
	}
	bool operator ==(const Frac &rhs) const
	{
		return (intl)n * rhs.d == (intl)d * rhs.n;
	}
	double value() { return (double)n / d; }
};
class Cmp
{
public:
	bool operator ()(const pair<Frac, int> &lhs, const pair<Frac, int> &rhs)
	{
		if(lhs.first == rhs.first)
			return lhs.second < rhs.second;
		return lhs.first < rhs.first;
	}
};

int t;
int p[N];
intl l[N];

Frac frac(int pos, int use)
{
	return Frac(p[pos] * l[pos], (l[pos] + use) * (l[pos] + use + 1));
}

int use[N];
double ans = 0;
set <pair <Frac, int>, Cmp> up, down;
void d(int pos)
{
	if(up.find({frac(pos, use[pos]), pos}) != up.end())
		up.erase(up.find({frac(pos, use[pos]), pos}));
	if(down.find({frac(pos, use[pos] - 1), pos}) != down.end())
		down.erase(down.find({frac(pos, use[pos] - 1), pos}));	
}
void a(int pos)
{
	if(use[pos] < l[pos])
		up.insert({frac(pos, use[pos]), pos});
	if(use[pos] != 0)
		down.insert({frac(pos, use[pos] - 1), pos});
}

void add(int pos)
{
	d(pos);
	//assert(use[pos] != l[pos]);
	ans += frac(pos, use[pos] ++).value();
	a(pos);
	t --;
}
void del(int pos)
{
	d(pos);
	ans -= frac(pos, -- use[pos]).value();
	a(pos);
	t ++;
}
void balance(bool f = false)
{
	int cnt = 0;
	while(true)
	{
		if(t > 0 && up.size())
			add((--up.end()) -> second);
		else if(up.size() && down.size() &&
			(down.begin() -> first) < ((--up.end()) -> first))
		{
			int u = down.begin() -> second;
			int v = (--up.end()) -> second;
			assert(u != v);
			del(u);
			add(v);
		}
		else
			break;
	}
}

int main()
{
	int n, q;
	cin >> n >> t >> q;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> l[i];
		up.insert({frac(i, 0), i});
	}
	balance(true);
	for(int _ = 1; _ <= q; _ ++)
	{
		int type, pos;
		cin >> type >> pos;
		if(type == 1)
		{
			ans -= (double)p[pos] * use[pos] / (l[pos] + use[pos]);
			ans += (double)p[pos] * use[pos] / (l[pos] + use[pos] + 1);
			d(pos);
			l[pos] ++;
			a(pos);
		}
		else
		{
			if(use[pos] == l[pos])
			{
				t ++;
				ans -= (double)p[pos] * use[pos] / (l[pos] + use[pos]);
				ans += (double)p[pos] * (use[pos] - 1) / (l[pos] + use[pos] - 2);
				d(pos);
				use[pos] --;
				l[pos] --;
				a(pos);
			}
			else
			{
				ans -= (double)p[pos] * use[pos] / (l[pos] + use[pos]);
				ans += (double)p[pos] * use[pos] / (l[pos] + use[pos] - 1);
				d(pos);
				l[pos] --;
				a(pos);
			}
		}
		balance();
		cout << setprecision(8) << ans << '\n';
	}
	return 0;
}