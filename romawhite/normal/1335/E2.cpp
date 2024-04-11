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
typedef long long ll;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 1000000007; 
 
VI G[200];
 
int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
 
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		VI A(n);
 
		FOR(i,0,200) {
			G[i].clear();
		}
 
		FOR(i,0,n) {
			cin >> A[i];
			A[i] --;
			G[A[i]].push_back(i);
		}
 
		int res = 0;
		FOR(i,0,200) {
			res = max(res, SZ(G[i]));
			FOR(j,0,SZ(G[i]) / 2) {
				int l = G[i][j] + 1;
				int r = G[i][SZ(G[i]) - j - 1];
 
				FOR(k,0,200) {
					int cnt = lower_bound(ALL(G[k]), r) - lower_bound(ALL(G[k]), l);
					res = max(res, 2 * (j + 1) + cnt);
				}
 
			}
		}
		cout << res << endl;
 
	}
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}