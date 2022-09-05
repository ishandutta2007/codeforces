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
const int MAX = 200007;
const int MOD = 998244353;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool U[1007][1007];

int N;

bool inside(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}
int A[1007][1007];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n;
		cin >> n;
		N = n;
		FOR(i,0,n)
			FOR(j,0,n)
				U[i][j] = false;
		FOR(i,0,n)
			FOR(j,0,n)
				cin >> A[i][j];
		int res = 0;
		FOR(i,0,n) {
			FOR(j,0,n) {
				if((i + j) % 2 == 1)
					continue;
				bool ok = true;
				FOR(dir,0,4) {
					int xx = i + dx[dir];
					int yy = j + dy[dir];
					if (inside(xx, yy) && U[xx][yy])
						ok = false;
				}
				if (ok) {
					res ^= A[i][j];
					res ^= A[n - 1 - i][j];
					FOR(dir,0,4) {
					int xx = i + dx[dir];
					int yy = j + dy[dir];
					if (inside(xx, yy))
						U[xx][yy] = true;
					}
				}
			}
		}
		cout << res << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}