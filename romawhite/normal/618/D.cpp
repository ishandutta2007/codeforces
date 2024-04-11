#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const Int INF2 = 1LL * INF * INF;
const int MAX = 200007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

VI g[MAX];

int n , x , y;

int res = 0;

int dfs(int v, int p)
{
	int cnt = 0;
	FOR(i,0,g[v].size())
	{
		int to = g[v][i];
		if (to == p) continue;
		int r = dfs(to, v);
		if (r == 1)
		{
			++cnt;
		}
		else
		{
			++res;
		}
	}
	res += max(0, cnt - 2);
	return cnt <= 1;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);
	//freopen("out.txt" , "w" , stdout);

	cin >> n >> x >> y;
	if (n == 2)
	{
		cout << x << endl;
		return 0;
	}

	FOR(i,0,n - 1)
	{
		int a , b;
		scanf("%d %d" , &a , &b);
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if (x > y)
	{
		bool t = 0;
		FOR(i,0,n)
			if (g[i].size() == n - 1)
			{
				t = 1;
			}
		if (t == 1)
		{
			cout << 1LL * y * (n - 2) + x << endl;
		}
		else
		{
			cout << 1LL * y * (n - 1) << endl;
		}
		return 0;
	}

	dfs(0, -1);
	Int R = 1LL * res * y + 1LL * (n - 1 - res) * x;
	cout << R << endl;

    return 0;
}