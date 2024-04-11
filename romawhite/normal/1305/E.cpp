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
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1007;



int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;


    VI A;

    FOR(i,0,n) {
        if (i == 0) {
            A.push_back(1);
            continue;
        }
        if (i == 1) {
            A.push_back(2);
            continue;
        }
        if (m >= i / 2) {
            A.push_back(i + 1);
            m -= i / 2;
        } else {
            if (m > 0) {
                A.push_back(i + i - 2 * m + 1);
                m = 0;
            } else {
                A.push_back(1e8 + 1e4 * i);
            }
        }
    }   

    if (m == 0) {
        FOR(i,0,SZ(A))
            cout << A[i] << ' ';
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }


    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}