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
vector<int> a;

bool read() {
	if (!(cin >> n))
		return false;
	a.resize(n);
	forn (i, n)
		scanf("%d", &a[i]);
	return true;
}

bool ok (int m)
{
	int l = m - 1, r = n - 1;
	int cnt = 0;
	while (l >= 0)
	{
		if (a[l] * 2 <= a[r])
		{
			cnt++;
			r--;
			l--;
		}
		else
			break;
	}
	if (r < m - 1)
		return false;
	return cnt == m;
}

void solve() {
	sort(all(a));
	int ans = n;
	int l = 0, r = n / 2 + 1;
	while (r - l > 1)
	{
		int m = (r + l) / 2;
		if (ok(m))
			l = m;
		else
			r = m;
	}
	while (ok(l + 1))
		l++;
	cout << ans - l << endl;
}

int main() {
#ifdef SU6 
	freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
#endif
	while (read())
        solve();
    return 0;
}