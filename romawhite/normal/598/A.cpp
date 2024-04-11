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
const int MAX = 1007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int n;
        cin >> n;
        Int res = 1LL * n * (n + 1) / 2;
        int l = 1;
        while (l <= n)
        {
            res -= 2 * l;
            l *= 2;
        }
        cout << res << endl;
    }


    return 0;
}