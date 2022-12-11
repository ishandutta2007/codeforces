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

const int nmax = 250;

int n;
int a[nmax];
int g[nmax][nmax];
int64 d[nmax];

int64 gcd(int64 a, int64 b) {
    if (a == 0 )return b;
    return gcd(b % a, a);
}

int64 nok(int64 a, int64 b) {
    int64 c = gcd(a, b);
    return (a / c) * b;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n;
    forn(i, n)
        forn(j, n)
            g[i][j] = 1e9;

    forn(i, n) {
        cin >> a[i];
        a[i] --;
        g[i][a[i]] = 1;
    }

    int64 res = 1;          


    forn(k, n)
        forn(i, n)
            forn(j, n)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    forn(i, n)
        d[i] = 1e9;
    forn(i, n)
        if (g[i][i] < 1e9) {
            res = nok(res, g[i][i]);
            d[i] = 0;
        }
    forn(i, n)
        forn(j, n)
            d[i] = min(d[i], g[i][j] + d[j]);
    int64 K = 1;
    forn(i, n) 
        if (d[i] > 0) {
            int64 now = (d[i] - 1) / res;
            K = max(K, (now + 1));
        }
    cout << res * K << endl;
    return 0;
}