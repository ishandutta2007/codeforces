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

int a[200][200];

int calc(int m) {
    if (m == 0) return 1;
    int now = 1;
    while (now * 2 <= m) now *= 2;
    return 1 + calc(m - now);
}

int64 c[50][50];

int64 solve(int64 n, int t) {
    if (t == 0) return 1;
    if (n == 0) {
        if (t == 0) return 1;
        return 0;
    }
    int64 w = 1, p = 1;
    while (w * 2 <= n) {
        w *= 2;
        p ++;
    }
    if (t > p) return 0;
    return solve(n - w, t - 1) + c[p-1][t];
}

int64 sol1(int n, int nt) {
    int res=  0;
    for (int i = 1; i <= n; i ++)
        if (calc(i + 1) - 1 == nt) res ++;
    return res;
}


void no() {
    puts("0");
    exit(0);
}

int64 sol(int64 n, int64 nt) {
    int64 res = solve(n+1, nt);
    if (nt == 1) res --;
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    

    c[0][0] = 1;
    forn(i, 50)
        forn(j, i + 1) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
      
    int64 n, t;
    cin >> n >> t;
    int nt = 1;
    while (t > 1) {
        if (t % 2 != 0) no();
        t /= 2;
        nt ++;
    }
    cout << sol(n, nt) << endl;
    
    return 0;
}