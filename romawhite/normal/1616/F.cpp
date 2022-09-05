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
const int MAX = 100;
const int MOD = 1000000007;

int A[MAX][MAX];

int gauss (vector < VI > a, VI & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (a[i][col] != 0)
                sel = i;
        if (a[sel][col] == 0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = (a[i][col] * a[row][col]) % 3;;
                for (int j=col; j<=m; ++j)
                    a[i][j] = (a[i][j] - a[row][j] * c % 3 + 3) % 3;
            }
        ++row;
		// cout << endl;
		// FOR(i,0,SZ(a)) {
		// 	FOR(j,0,SZ(a[i]))
		// 		cout << a[i][j] << ' ';
		// 	cout << endl;
		// }
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (a[where[i]][m] * a[where[i]][i]) % 3;
	// cout << "ANS" << endl;
	// FOR(i,0,SZ(ans)) {
	// 	cout << ans[i] << ' ';
	// }
	// cout << endl;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
		sum %= 3;
        if (sum != a[i][m])
            return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));
	int t;
	cin >> t;
	FOR(tt,0,t) {
		int n, m;
		cin >> n >> m;
		VI R(m);
		FILL(A, -1);
		int N = 0;
		FOR(i,0,m) {
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b;
			A[a][b] = i;
			A[b][a] = i;
			if (c > 0)
				R[i] = c - 1;
			else {
				++ N;
				R[i] = -N;
			}
		}
		vector<VI> G;
		FOR(i,0,n)
			FOR(j,i + 1,n)
				FOR(k,j + 1, n) {
					if (A[i][j] != -1 && A[i][k] != -1 && A[j][k] != -1) {
						// cout << 'x' << endl;
						VI a(N, 0);
						int b = 0;
						int c;
						c = R[A[i][j]];
						if (c >= 0)
							b += c;
						else
							a[-c - 1] = 1;
						c = R[A[i][k]];
						if (c >= 0)
							b += c;
						else
							a[-c - 1] = 1;
						c = R[A[j][k]];
						if (c >= 0)
							b += c;
						else
							a[-c - 1] = 1;
						b %= 3;
						a.push_back((3 - b) % 3);
						G.push_back(a);
					}
				}
		// FOR(i,0,SZ(G)) {
		// 	FOR(j,0,SZ(G[i]))
		// 		cout << G[i][j] << ' ';
		// 	cout << endl;
		// }
		VI ans;
		int t;
		if (SZ(G) == 0) {
			t = 1;
			ans = VI(N, 0);
		} else {
			t = gauss(G, ans);
		}
		if (t == 0) {
			cout << -1 << endl;
			continue;
		}
		FOR(i,0,SZ(R)) {
			if (R[i] < 0)
				R[i] = ans[-R[i] - 1];
		}
		FOR(i,0,SZ(R)) {
			cout << R[i] + 1 << ' ';
		}
		cout << endl;
	}

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}