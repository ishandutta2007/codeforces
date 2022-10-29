#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
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
char c[5010][5010];

bool read()
{
	scanf("%d%d\n", &n, &m);
	forn (i, n)
		gets(c[i]);
	return true;
}

struct otr
{
	int l, r;
};
otr mo (int a, int b)
{
	otr res = {a, b};
	return res;
}
bool cmp (otr a, otr b)
{
	if (a.l != b.l)
		return a.l < b.l;
	return a.r < b.r;
}

void solve()    
{
	vector<int> st[5000];
	vector<otr> v;
	forn (i, n)
	{
		int j = 0;
		while (j < m)
		{
			int l = j, r = j;
			while (r < m && c[i][r] == '1')
				r++;
			while (r != l)
				st[l++].pb(r - 1);
			j = max (j + 1, r);
		}
	}
	int ans = 0;
	forn (i, 5000)
	{
		sort(all(st[i]));
		forn (j, st[i].size())
			ans = max(ans, ((st[i][j] - i + 1) * ((int)st[i].size() - j)));
	}
	cout << ans << endl;
}

int main()
{
#ifdef Baster
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}