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
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1000007;
const int MOD = 998244353;

int p[MAX];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    // mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    int n, m, c;
    cin >> n >> m >> c;
    VI L;
    VI R;

    int mid = c / 2 + 1;

    while (true) {
        if (SZ(L) + SZ(R) == n)
            break;
        int x;
        cin >> x;
        if (x < mid) {
            if (SZ(L) == 0 || x >= L.back()) {
                L.push_back(x);
                cout << SZ(L) << endl;
            } else {
                int id;
                FOR(i,0,SZ(L)) {
                    if (L[i] > x) {
                        id = i;
                        break;
                    }
                }
                L[id] = x;
                cout << id + 1 << endl;
            }
        } else {
            if (SZ(R) == 0 || x <= R.back()) {
                R.push_back(x);
                cout << n + 1 - SZ(R) << endl;
            } else {
                int id;
                FOR(i,0,SZ(R)) {
                    if (R[i] < x) {
                        id = i;
                        break;
                    }
                }
                R[id] = x;
                cout << n - id << endl;
            }
        }
    }


	return 0;
}