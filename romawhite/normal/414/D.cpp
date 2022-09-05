#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100;
const int MAX2 = 7000;
const Int BASE = 1000000007;

const int MOD = 1000000007;

vector<int> g[100007];

bool used[100007];
int a[100007];

void dfs(int v,int d = -1)
{
	used[v] = 1;
	if (d != -1)
		a[d]++;
	FOR(i,0,g[v].size())
		if (!used[g[v][i]])
			dfs(g[v][i] , d + 1);
}

int main()
{
	int n,k,p;
	cin >> n >> k >> p;

	FOR(i,0,n - 1)
	{
		int a,b;
		scanf("%d%d" , &a , &b);
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);
	int res = 0;
	int j = 0;
	int price = 0;
	int t = 0;
	FOR(i,0,100007)
	{
		if (!a[i])
			break;
		price += t;
		t += a[i];
		while (price > p)
		{
			if (price - p >= a[j] * (i - j))
			{
				price -= a[j] * (i - j);
				t -= a[j];
				++j;
			}
			else
			{
				int r = (price - p + i - j - 1) / (i - j);
				a[j] -= r;
				price -= r * (i - j);
				t -= r;
			}
		}
		res = max(res , t);
	}
	res = min(res , k);
	cout << res << endl;

	return 0;
}