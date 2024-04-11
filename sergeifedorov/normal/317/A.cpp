#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

void write(int64 x) {
    cout << x << endl;
    exit(0);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    int64 x, y, m;
    cin >> x >> y >> m;
    int64 res = 0;
    while(1) {
        if (x >= m || y >= m) write(res);
        if (x <= 0 && y <= 0) write(-1);
        if (x < 0) {
            int64 now = max(1ll, abs(x / y));
            res += now;
            x += y * now;
            continue;
        }
        if (y < 0) {
            int64 now = max(1ll, abs(y / x));
            res += now;
            y += x * now;
            continue;
        }

        if (x < y)
            x = x + y;
        else
            y = y + x;
        res ++;
    }
    write(res);
    

    return 0;
}