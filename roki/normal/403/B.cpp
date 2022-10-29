#pragma comment(linker, "/STACK:256000000")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<iomanip>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n, m;
int a[5000], b[5000];

bool read()
{
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	forn (i, m)
		cin >> b[i];
	return true;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> f(int a)
{
	vector<int> res;
	for (int i = 2; i * i <= a; ++i)
		while (a % i == 0)
		{
			a /= i;
			res.push_back(i);
		}
	if (a > 1)
		res.push_back(a);
	return res;
}

unordered_set<int> bad;

int func  (vector<int> &v)
{
	int res = 0;
	forn (i, v.size())
	{
		if (bad.count(v[i]))
			res--;
		else
			res++;
	}
	return res;
}

void solve()
{
	forn (i, m)
		bad.insert(b[i]);

	int g = 1;
	vector<vector<int> > fact(n);
	int ans = -1e9;
	while (true)
	{
		g = a[0];
		int lg = g;
		vector<int> cf = f(g);
		int pos = -1, pg;
		forn (i, n)
		{
			g = gcd(g, a[i]);
			if (g != lg)
				cf = f(g), lg = g;
			if (func(cf) < 0)
				pos = i, pg = g;
		}
		if (pos == -1)
			break;
		forn (i, pos + 1)
			a[i] /= pg;
	}

	forn (i, n)
		fact[i] = f(a[i]);

		int sum = 0;
		int cur = func(f(g));
		forn (j, n)
				sum += func(fact[j]);
	
	cout << sum << endl;
}

int main()
{

#ifdef Baster
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif

	read();
	solve();

	return 0;
}