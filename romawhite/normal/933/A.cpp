

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
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
#include <time.h>
#include <complex>
#include <bitset>
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
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 2007;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int a[MAX];

int cnt[2][MAX][MAX];
int A[MAX][MAX];

int main()
{
    
    int n;
    cin >> n;
    FOR(i,0,n)
    {
        cin >> a[i];
        --a[i];
    }
    
    FOR(l,0,n)
    {
        FOR(r,l,n)
        {
            cnt[0][l][r] = (a[r] == 0);
            cnt[1][l][r] = (a[r] == 1);
            A[l][r] = 1;
            if (l != r)
            {
                cnt[0][l][r] += cnt[0][l][r - 1];
                cnt[1][l][r] += cnt[1][l][r - 1];
                
                if (a[r] == 0)
                {
                    A[l][r] = A[l][r - 1] + 1;
                }
                else
                {
                    A[l][r] = max(A[l][r - 1] , cnt[1][l][r]);
                }
                
            }
        }
    }
    
    int res = 0;
    FOR(l,0,n)
        FOR(r,l,n)
        {
            int rs = A[l][r];
            if (l != 0)
                rs += cnt[0][0][l - 1];
            if (r != n - 1)
                rs += cnt[1][r + 1][n - 1];
            res = max(res , rs);
        }
    
    cout << res << endl;
    
    return 0;
}