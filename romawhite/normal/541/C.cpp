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
const int MAX = 228;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];
int used[MAX];

Int gcd(Int a, Int b)
{
    if (!b) return a;
    return gcd(b , a % b);
}

int main()
{
      //freopen("in.txt","r",stdin);
 //   freopen("C:/output.txt" , "w" , stdout);

    int n;
    cin >> n;

    FOR(i,0,n)
    {
        cin >> a[i];
        --a[i];
    }

    int p = 0;
    Int r = 1;

    FOR(i,0,n)
    {
        int v = i;
        FILL(used, -1);
        for(int it = 0; ; ++it)
        {
            if (used[v] == -1)
            {
                used[v] = it;
                v = a[v];
            }
            else
            {
                int cycle = it - used[v];
                int path = used[v];
                p = max(path , p);
                Int g = gcd(r , cycle);
                r = r / g * cycle;
                break;
            }
        }
    }

    Int res = r;

    while (res < p)
    {
        res += r;
    }

    cout << res << endl;

    return 0;
}