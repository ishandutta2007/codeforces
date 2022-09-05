#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

string s[107];
Int a[107][107];

int main()
{
    //  freopen("in.txt","r",stdin);

    int n , m;
    cin >> n >> m;

    FOR(i,0,n)
    {
        cin >> s[i];
    }

    int res = 0;

    RFOR(i,n,0)
    {
        RFOR(j,m,0)
        {
            int c = (s[i][j] == 'W' ? 1: -1);
            if (c == a[i][j]) continue;
            int add = c - a[i][j];
            //cout << i << ' ' << j << ' ' << a[i][j] << ' ' << c << endl;
            FOR(x,0,i + 1)
            {
                FOR(y,0,j + 1)
                {
                    a[x][y] += add;
                }
            }

            ++res;

        }
    }

    cout << res << endl;

    return 0;
}