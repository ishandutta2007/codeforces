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

const int nmax = 100100;
const int64 mod = 1e9;

int n, m;
int a[nmax];
int64 f[nmax];

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    f[0] = f[1] = 1;
    for (int i = 2; i < nmax; i ++)
        f[i] = (f[i-1] + f[i-2]) % mod;
    cin >> n >> m;
    forn(i, n)
        cin >> a[i];
    forn(i, m) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            a[l - 1] = r;
            continue;
        }
        l --;
        r --;
        int64 res = 0;
        for (int i = l; i <= r; i ++)
            res = (res + a[i] * f[i-l]) % mod;
        cout << res << endl;        
    }

    return 0;
}