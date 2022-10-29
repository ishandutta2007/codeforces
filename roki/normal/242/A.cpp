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

int x, y, a, b;

inline bool read()
{
	if(!(cin >> x >> y >> a >> b))
		return false;
	return true;
}

inline void solve()
{
	vector<pair<int, int>> ans;
	for (int i = a; i <= x; ++i)
		for (int j = b; j < min(i, y + 1); ++j)
			ans.pb(mp(i, j));
	cout << ans.size() << endl;
	forn (i, ans.size())
		cout << ans[i].first << ' ' << ans[i].second << endl;
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