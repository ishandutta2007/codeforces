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
const int MOD = 1000000007;

int p[] = {4, 1, 3, 2, 0, 5};

int f(int x) {
    int res = 0;
    FOR(i,0,6) {
        if (x & (1 << i)) {
            res += (1 << p[i]);
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);
    
    // cout << f(2) << endl;
    // cout << f(5) << endl;
    // cout << f(35) << endl;

    int n;
    cin >> n;
    cout << f(n) << endl;
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}