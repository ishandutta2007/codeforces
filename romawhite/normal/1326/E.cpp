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
const int MAX = 300007;
const int MOD = 998244353;

int t[4 * MAX];
int p[4 * MAX];

void push(int v) {
    if (p[v] != 0) {
        t[2 * v + 1] += p[v];
        p[2 * v + 1] += p[v];

        t[2 * v + 2] += p[v];
        p[2 * v + 2] += p[v];

        p[v] = 0;
    }
}

void Upd(int v, int l, int r, int L, int R, int val) {
    if (L > R) return;
    if (l == L && r == R) {
        t[v] += val;
        p[v] += val;
        return;
    }
    push(v);
    int m = (l + r) / 2;
    Upd(2 * v + 1, l, m , L, min(R, m), val);
    Upd(2 * v + 2, m + 1, r, max(L, m + 1), R, val);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // mt19937 rng(47);

    int n;
    cin >> n;
    VI p(n);
    VI q(n);
    FOR(i,0,n) {
        cin >> p[i];
        -- p[i];
    }

    FOR(i,0,n) {
        cin >> q[i];
        -- q[i];
    }

    VI A(n);
    FOR(i,0,n) {
        A[p[i]] = i;
    }


    VI res(n);
    int L = 0;
    RFOR(i,n,0) {
        Upd(0, 0, n - 1, 0, A[i], -1);
        while (L < n && t[0] < 0) {
            res[L] = i + 1;
            Upd(0, 0, n - 1, 0, q[L], 1);
            ++ L;
        }
    }

    FOR(i,0,n) {
        cout << res[i] << ' ';
    }
    cout << endl;
    
    
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}