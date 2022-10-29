#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n;
bitset<2000> ch[2000];

set<pair<int, int>> s;

inline void read()
{
	cin >> n;
	forn (i, n)
	{
		int a;
		cin >> a;
		a--;
		if(a != -2)
		{
			ch[a][i] = true;
			s.insert(mp(1, i));
		}
		else
			s.insert(mp(0, i));
	}
}

inline void solve()
{
	int ans = 0;
	while(s.size() > 0)
	{
		ans++;
		bitset<2000> nt;
		while(s.size() > 0 && s.begin()->first == 0)
		{
			nt |= ch[s.begin()->second];
			s.erase(s.begin());
		}
		forn (i, n)
			if(nt[i])
			{
				s.erase(mp(1, i));
				s.insert(mp(0, i));
			}
	}
	cout << ans << endl;
}

int main()
{
#ifdef Baster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    read();
    solve();
    return 0;
}