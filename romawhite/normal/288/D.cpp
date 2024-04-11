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
 
#define next fgdfvd
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
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int MOD = 1000000007;
const int MAX = 100000;
const int INF = 100000000;

vector<int> g[80007];

LL dp[80007];
LL dp2[80007];
LL r[80007];
LL r2[80007];

char used[80007];

LL res = 0;
LL n;
void dfs(int v){
	used[v] = 1;
	dp[v] = 1;
	LL sq = 0;
	dp2[v] = 0;
	r2[v] = 0;
	FOR(i,0,g[v].size())
		if (!used[g[v][i]]){
			dfs(g[v][i]);
			dp[v] += dp[g[v][i]];
			dp2[v] += dp2[g[v][i]];
			r2[v] += r2[g[v][i]];
			sq += dp[g[v][i]] * dp[g[v][i]];
		}
	dp2[v] += dp[v];

	r[v] = ((dp[v] - 1) * (dp[v] - 1) - sq) / 2 + dp[v] - 1;

	res += r[v] * r2[v];
	r2[v] += r[v];

	res +=  r[v] * (n - dp[v]) * (n - dp[v] - 1) / 2;

}
 

int main()
{
	//freopen("in.txt", "r", stdin);
	cin >> n;
	FOR(i,0,n - 1){
		int a,b;
		scanf("%d%d" , &a , &b);
		--a;--b;
		g[a].PB(b);
		g[b].PB(a);
	}

	FILL(used, 0);
	dfs(0);

	FOR(i,0,n)
		res -= dp[i] * r[i] * (n - dp[i]);

	cout << res << endl;
    return 0;
}