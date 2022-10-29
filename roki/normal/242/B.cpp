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

inline bool read()
{
	if(!(cin >> n))
		return false;
	return true;
}

inline void solve()
{
	int minv = 1e9, maxv = -1e9;
	int a[100000], b[100000];
	forn (i, n)
	{
		scanf("%d%d", &a[i], &b[i]);
		minv = min(minv, a[i]);
		maxv = max(maxv, b[i]);
	}
	forn (i, n)
		if(a[i] == minv && b[i] == maxv)
		{
			cout << i + 1 << endl;
			return;
		}
	cout << -1;
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