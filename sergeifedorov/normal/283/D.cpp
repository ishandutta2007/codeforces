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

const int nmax = 6000;

int n;
int dp[nmax];
int64 c[nmax], d[nmax], a[nmax];


bool good(int64 a, int64 b, int64 c, int64 d, int dst) {
    if (a % c != 0)
        return 0;
    if (d < dst) return 1;
    if (b + dst == d) return 1;
    return 0;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n) {
        cin >> a[i];
        c[i] = d[i] = 0;
        int64 now = a[i];
        while (now % 2 == 0) {
            now /= 2;
            d[i] ++;
        }
        c[i] = now;
    }
    
    int res = 0;
    forn(i, n) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j --) {
            if (good(c[j], d[j], c[i], d[i], i - j))
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
        }
        cout << n - res << endl;
    

    return 0;
}