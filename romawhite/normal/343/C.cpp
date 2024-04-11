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
const int MAX = 100007;
const int MOD = 1000000007;

vector<Int> A, B;

bool f(Int x) {
    int id = 0;
    FOR(i,0,SZ(A)) {
        if (id == SZ(B))
            return true;
        if (B[id] >= A[i]) {
            while (id < SZ(B) && B[id] <= A[i] + x)
                ++ id;
        } else {
            if (A[i] - x > B[id])
                return false;
            Int l = A[i] - B[id];
            Int c = max(x - 2 * l, (x - l) / 2);
            while (id < SZ(B) && B[id] <= A[i] + c)
                ++ id;
        }
        if (id == SZ(B))
            return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
	// ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    A.resize(n);
    B.resize(m);
    
    FOR(i,0,n) {
        cin >> A[i];
    }
    FOR(i,0,m) {
        cin >> B[i];
    }

    Int L = 0;
    Int R = 1000000000000LL;

    while (R - L > 1) {
        Int M = (L + R) / 2;
        if (f(M))
            R = M;
        else
            L = M;
    }
    if (f(L))
        R = L;

    cout << R << endl;

	return 0;
}