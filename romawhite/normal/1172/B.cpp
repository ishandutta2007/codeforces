#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const Int LINF = INF * (Int) INF;
 
const int MAX = 200007;
 
const int MOD = 998244353;

VI G[MAX];
Int R[MAX];
Int F[MAX];
int sz[MAX];

void dfs(int v, int p)
{
	R[v] = 1;
	int s = 0;
	sz[v] = 1;
	for(int to: G[v])
	{
		if (to == p)
			continue;
		++ s;
		dfs(to, v);
		sz[v] += sz[to];
		R[v] *= R[to];
		R[v] %= MOD;
	}
	if (p != -1)
	{
		R[v] *= F[s + 1];
		R[v] %= MOD;
	}
	else
	{
		R[v] *= F[s];
		R[v] %= MOD;
		R[v] *= sz[v];
		R[v] %= MOD;
	}
}

int main(int argc, char* argv[])
{
	// freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);
	
	F[0] = 1;
	FOR(i,1,MAX)
	{
		F[i] = F[i - 1] * i % MOD;
	}

	int n;
	cin >> n;

	FOR(i,0,n - 1)
	{
		int a , b;
		cin >> a >> b;
		--a;--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(0, -1);
	cout << R[0] << endl;

	// cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}