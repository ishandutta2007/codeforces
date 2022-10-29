#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>
#include<time.h>
#include<bitset>
#include<ctime>

using namespace std;

const int INF = 1e9;
const double pi = 3.14159265358979323846;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int n, m, h, t;
vector<int> g[100000];

inline bool read()
{
	if(!(cin >> n >> m >> h >> t))
		return false;
	forn (i, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return true;
}

int used[100000];
int ct = 1;

inline void solve()
{
	forn (i, n)
		forn (j, g[i].size())
	{
		int head = i, tail = g[i][j];
		if(g[head].size() < h + 1 || g[tail].size() < t + 1)
			continue;
		else
		{
			ct++;
			forn (iter, g[head].size())
				used[g[head][iter]] = ct;
			int cnt = 0;
			ct++;
			forn (iter, g[tail].size())
			{
				if(used[g[tail][iter]] == ct - 1)
					cnt++;
				used[g[tail][iter]] = ct;
			}
			int need = max(h - (int)g[head].size() + cnt + 1, 0);
			if((int)g[tail].size() - need - 1 < t)
				continue;
			cout << "YES" << endl;
			cout << head + 1 << ' ' << tail + 1 << endl;
			forn (it, g[head].size())
			{
				if(h == 0)
					break;
				if(g[head][it] == tail)
					continue;
				if(used[g[head][it]] == ct)
				{
					if(need > 0)
					{
						need--;
						h--;
						used[g[head][it]] = ct + 1;
						cout << g[head][it] + 1 << ' ';
					}
				}
				else
				{
					cout << g[head][it] + 1 << ' ';
					h--;
				}
			}
			cout << endl;
			forn (it, g[tail].size())
			{
				if(g[tail][it] == head)
					continue;
				if(t == 0)
					break;
				if(used[g[tail][it]] != ct + 1)
				{
					cout << g[tail][it] + 1 << ' ';
					t--;
				}
			
			}
			return;
		}
	}
	cout << "NO" << endl;
}

int main()
{
#ifdef Baster
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	while(read())
		solve();

	return 0;
}