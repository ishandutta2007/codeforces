#include <bits/stdc++.h>
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
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1 << 20;
const int MOD = 1000000007;

int C[MAX];
VI G[MAX];
bool U[MAX];

int dfs(int v) {
	int res = C[v];
	U[v] = true;
	for(int to: G[v]) {
		if (U[to])
			continue;
		res = min(res, dfs(to));
	}
	return res;
}

int F(VI & C, int M) {
	int cnt = 0;
	FOR(i,0,SZ(C))
		if (C[i] > M)
			++ cnt;
	return cnt <= M + 1;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n, k;
		cin >> n >> k;
		vector<pair<PII, int> > X;
		vector<pair<PII, int> > Y;
		FOR(i,0,n) {
			G[i].clear();
			U[i] = 0;
		}
		FOR(i,0,n) {
			int x, y, t;
			cin >> x >> y >> t;
			X.push_back(MP(MP(x, y), i));
			Y.push_back(MP(MP(y, x), i));
			C[i] = t;
		}
		sort(ALL(X));
		sort(ALL(Y));
		FOR(i,0,SZ(X) - 1) {
			if (X[i].first.first == X[i + 1].first.first && X[i + 1].first.second - X[i].first.second <= k) {
				int a = X[i].second;
				int b = X[i + 1].second;
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}
		FOR(i,0,SZ(Y) - 1) {
			if (Y[i].first.first == Y[i + 1].first.first && Y[i + 1].first.second - Y[i].first.second <= k) {
				int a = Y[i].second;
				int b = Y[i + 1].second;
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}

		VI C;
		FOR(i,0,n) {
			if (!U[i])
				C.push_back(dfs(i));
		}

		int L = 0;
		int R = INF;
		while (R - L > 1) {
			int M = (L + R) / 2;
			if (F(C, M))
				R = M;
			else
				L = M;
		}
		if (F(C, L))
			R = L;

		cout << R << endl;


		

	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}