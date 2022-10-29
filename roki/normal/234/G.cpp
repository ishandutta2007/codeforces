#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define xrange(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long li;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n;

bool read() {
	if (!(cin >> n))
		return false;
	return true;
}
	
vector< vector<int> > team;
vector< vector<int> > ans;
vector<int> tmp;

bool split ()
{
	tmp.clear();
	vector< vector<int> > ost;
	forn (i, team.size())
	{
		if (team[i].size() > 1)
		{
			int nt = team[i].size() / 2;
			vector<int> push;
			for (int j = nt; j < team[i].size(); ++j)
			{
				push.pb(team[i][j]);
				tmp.pb(team[i][j]);
			}
			ost.pb(push);
			team[i].resize(nt);
		}
	}
	if (tmp.size() == 0)
		return false;
	forn (i, ost.size())
		team.pb(ost[i]);
	return true;
}

void solve() {
	vector<int> cur;
	forn (i, n)
		cur.pb(i);
	team.pb(cur);
	while (split())
		ans.pb(tmp);
	cout << ans.size() << endl;
	forn (i, ans.size())
	{
		cout << ans[i].size();
		forn (j, ans[i].size())
			cout << ' ' << ans[i][j] + 1;
		cout << endl;
	}
}

int main() {

	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	
read();
	solve();
	return 0;
}