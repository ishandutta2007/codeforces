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
#include <sstream>

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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 1010;
const long long mod = 1e9 + 7;

long long t[nmax][nmax];
long long s[nmax][nmax], sk[nmax][nmax];
long long o[nmax][nmax];

void pre_calc(){
    forn(i, nmax)
        t[0][i] = 1;
    t[0][0] = 0;
    for (int j = 0; j < nmax - 2; j ++){
        s[j][0] = 0;
        for (int i = 0; i < nmax - 2; i++)
            s[j][i+1] = (s[j][i] + t[j][i]) % mod;
        for (int i = 0; i < nmax - 2; i ++)
            sk[j][i+1] = (sk[j][i] + t[j][i] * i) % mod;
        for (int i = 1; i < nmax - 2; i++)
            t[j+1][i] = ((s[j][i-1] * (i - 1) - sk[j][i-1]) % mod + mod) % mod;
     }

}

int main ()
{
    int n, m, k;
    cin >> n >> m >> k;
    pre_calc();
    long long res = (t[k][n] * t[k][m]) % mod;
    cout << res << endl;


    return 0;
}