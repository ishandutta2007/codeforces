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

int n;
vector<int> a;

inline bool read()
{
	if(!(cin >> n))
		return false;
	a.resize(n);
	forn (i, n)
		scanf("%d", &a[i]);
	return true;
}

inline void solve()
{
	set<int> s;
	s.insert(0);
	set<int> ans;
	forn (i, n)
	{
		set<int> nt;
		s.insert(a[i]);
		for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
		{
			nt.insert(*it | a[i]);
			ans.insert(*it | a[i]);
		}
		s = set<int> (nt);
	}
	cout << ans.size() << endl;
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