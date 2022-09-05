#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
#define FILL(A, value) memset(A, value, sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MOD = 998244353;
const double Pi = acos(-1.);

const int MAX = 2002000;

int main()
{
    int b, k;
    cin >> b >> k;
    VI A(k);
    FOR(i, 0, k)
    cin >> A[i];
    bool odd = false;
    if (b % 2 == 0)
    {
        odd = A.back() % 2;
    }
    else
    {
        int s = 0;
        FOR(i, 0, k)
        s += A[i];
        odd = s % 2;
    }
    if (!odd)
        cout << "even" << endl;
    else
    {
        cout << "odd" << endl;
    }

    return 0;
}