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

int n, k;
vector<int> a;

bool read() {
	if (!(cin >> n >> k))
		return false;
	a.resize(n);
	forn (i, n)
		cin >> a[i];
    return true;
}

void solve(){
	vector<li> sum(n + 1);
	forn (i, n)
		sum[i + 1] = sum[i] + a[i];
	vector<li> dp(n + 1, -1e9);
	vector<int> from(n + 1);
	for (int i = n - k; i >= 0; --i)
	{
		if (sum[i + k] - sum[i] >= dp[i + 1])
		{
			from[i] = i;
			dp[i] = sum[i + k] - sum[i];
		}
		else
		{
			from[i] = from[i + 1];
			dp[i] = dp[i + 1];
		}
	}
	li ans = -1e9;
	pair<int, int> anspos;
	forn (i, n - 2 * k + 1)
	{
		if (sum[i + k] - sum[i] + dp[i + k] > ans)
		{
			ans = sum[i + k] - sum[i] + dp[i + k];
			anspos = mp(i, from[i + k]);
		}
		else
			if (sum[i + k] - sum[i] + dp[i + k] == ans && from[i + k] < anspos.second)
			{
				ans = sum[i + k] - sum[i] + dp[i + k];
				anspos = mp(i, from[i + k]);
			}
	}
	cout << anspos.first + 1 << ' ' << anspos.second + 1 << endl;
}

int main() {
#ifdef SU6
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}