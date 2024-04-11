#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;

int x[N];
int y[N];

bool solve(string s, string t)
{
	set<string> mem;
	mem.insert(s);
	for (int i = 0; i < 30; ++i)
	{
		set<string> st1;
		for (auto x : mem)
		{
			//cerr << x << '\n';
			for (int j = 0; j < x.size(); ++j)
			{
				if (j + 3 <= x.size() && x.substr(j, 3) == "AAA")
				{
					string y = x.substr(0, j) + x.substr(j + 3, x.size() - j - 3);
					st1.insert(y);
				}
				string y = x.substr(0, j);
				if (x[j] == 'A')
					y += "BB";
				if (x[j] == 'B')
					y += "AB";
				if (x[j] == 'C')
					y += "AB";
				y += x.substr(j + 1, x.size() - j - 1);
				st1.insert(y);
			}
		}
		for (auto x : st1)
			if (x.size() < 10)
				mem.insert(x);
	}
	return mem.count(t);
}

const bool deb = false;

int main()
{
beg:
    ios::sync_with_stdio(0);
    string s, t;
    cin.tie(0);
	if (deb)
	{
		int n = rand() % 7 + 1;
		int m = rand() % 7 + 1;
		for (int i = 0; i < n; ++i)
			s.push_back('A' + rand() % 2);
		for (int i = 0; i < m; ++i)
			t.push_back('A' + rand() % 2);
	}
	else
	{
		cin >> s >> t;
		//cerr << solve(s, t) << '\n';
	}
    int n = (int) s.size(), m = (int) t.size();
	fill(x, x + N, 0);
	fill(y, y + N, 0);
	vector<int> ps(n + 1), pt(m + 1);
	for (int i = 0; i < n; ++i)
		ps[i + 1] = ps[i] + int(s[i] == 'A');
	for (int i = 0; i < m; ++i)
		pt[i + 1] = pt[i] + int(t[i] == 'A');
    for (int i = 0; i < n; i++)
    {
        if (i != 0) x[i] = x[i - 1];
        if (s[i] != 'A')
        {
            x[i]++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (i != 0) y[i] = y[i - 1];
        if (t[i] != 'A')
        {
            y[i]++;
        }
    }
    int q;
	if (deb)
		q = 1;
	else
		cin >> q;
    while (q--)
    {
        int a, b, c, d;
		if (deb)
		{
			a = 0, b = n - 1, c = 0, d = m - 1;
			//a = rand() % s.size(), b = rand() % s.size(), c = rand() % s.size(), d = rand() % s.size();
			if (a > b)
				swap(a, b);
			if (c > d)
				swap(c, d);
		}
		else
		{
			cin >> a >> b >> c >> d;
			a--, b--, c--, d--;
		}
        int l = x[b] - (a ? x[a - 1] : 0);
        int r = y[d] - (c ? y[c - 1] : 0);
		bool ok = true;
        if (l == 0)
        {
            if (b - a + 1 == d - c + 1 && r == 0)
            {
                cout << 1;
                continue;
            }
        }
		ok &= l % 2 == r % 2;
		int L = a - 1, R = b + 1;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			if (ps[b + 1] - ps[M] == b + 1 - M)
				R = M;
			else
				L = M;
		}
		int la = b + 1 - R;
		L = c - 1, R = d + 1;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			if (pt[d + 1] - pt[M] == d + 1 - M)
				R = M;
			else
				L = M;
		}
		int ra = d + 1 - R;
		if (la == ra && la == b - a + 1 && l < r)
			ok = false;
		if (la < ra)
			ok = false;
		if (la % 3 != ra % 3)
			l += 2;
		if (l > r)
			ok = false;
		if (deb)
		{
			int ans = solve(s, t);
			if (ans != ok)
			{
				cout << s << ' ' << t << ' ' << ans << ' ' << ok << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';
				return 239;
			}
			cerr << ok << ans << '\n';
		}
		else
			cout << ok;
    }
	if (!deb)
		cout << '\n';
	if (deb)
		goto beg;
}