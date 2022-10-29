#pragma comment(linker, "/STACK:256000000")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
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

int n, p;

bool read()
{
	cin >> n >> p;
	return true;
}

void solve()
{

	bool edge[25][25];
	forn (i, n)
		forn (j, n)
		edge[i][j] = false;
	set<pair<int, int> > s;
	forn (i, n)
		s.insert(mp(0, i));
	forn (i, 2 * n + p)
	{
		bool ok = true;
		for (set<pair<int, int> >::iterator it1 = s.begin(); ok && it1 != s.end(); ++it1)
		{
			for (set<pair<int, int> >::iterator it2 = s.begin(); ok && it2 != s.end(); ++it2)
			{
				if (!edge[it1->second][it2->second] && it1 != it2)
				{
					edge[it1->second][it2->second] = true;
					pair<int, int> a = *it1;
					pair<int, int> b = *it2;
					s.erase(it1);
					s.erase(it2);
					a.first++, b.first++;
					s.insert(a);
					s.insert(b);
					ok = false;
					break;
				}
			}
			if (!ok)
				break;
		}
	}
	forn (i, n)
		forn (j, n)
		if (edge[i][j])
			cout << i + 1 << ' ' << j + 1 << endl;
}

int main()
{

#ifdef Baster
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	forn (i, t)
	{
		read();
		solve();
	}

	return 0;
}