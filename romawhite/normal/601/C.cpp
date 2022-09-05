#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <cassert>
#include<complex>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef complex<double> base;

const int INF = 1000000000;
const int MAX = 107;
const int MAXE = 5000;
const int MAXV = 20*20;
const int BASE = 1000000007;
const int MOD = 1000000007;

double dp[MAX][100007];
int x[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    dp[0][0] = 1;
    int s = 0;
    int n , m;
    cin >> n >> m;
    FOR(i,0,n)
    {
        cin >> x[i];
        --x[i];
        s += x[i];
    }

    if (m == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    FOR(i,0,n)
    {
        double sum = 0;
        FOR(j,0,s)
        {
            sum += dp[i][j];
            if (j >= m)
            {
                sum -= dp[i][j - m];
            }
            double ss = sum;
            if (j >= x[i])
            {
                ss -= dp[i][j - x[i]];
            }
            dp[i + 1][j] = ss / (m - 1);
        }
    }

    double p = 0;
    FOR(i,0,s)
    {
        p += dp[n][i];
    }
    p *= m - 1;
    p += 1;
    printf("%.10f\n" , p);

    return 0;
}