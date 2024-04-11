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
const int MAX = 100007;

int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    int L = 0;
    int R = SZ(s) - 1;

    VI A;

    int n = SZ(s);

    while (true) {
        while (L < n && s[L] == ')') ++ L;
        while (R >= 0 && s[R] == '(') -- R;
        if (L < R) {
            A.push_back(L);
            A.push_back(R);
            ++ L;
            -- R;
        }
        else
        {
            break;
        }
    }

    if (SZ(A) == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << SZ(A) << endl;
    sort(ALL(A));
    FOR(i,0,SZ(A))
    {
        cout << A[i] + 1 << ' ';
    }
    cout << endl;

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}