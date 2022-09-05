

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

bool U[8];

int main()
{
    Int p , k;
    cin >> p >> k;
    
    VI res;
    
    int t = 0;
    
    while (p)
    {
        if (t == 0)
        {
            res.push_back(p % k);
            p /= k;
        }
        else
        {
            res.push_back((k - p % k) % k);
            p = (p + k - 1) / k;
        }
        t ^= 1;
    }
    
    
    cout << SZ(res) << endl;
    FOR(i,0,SZ(res))
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    
    
    
    
    return 0;
}