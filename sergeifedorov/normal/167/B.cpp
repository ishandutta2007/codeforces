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

const int nmax = 210;

int n, k, l;
int a[nmax];
double p[nmax];
double t[nmax][nmax][nmax];



int main ()
{
    cin >> n >> l >> k;
    forn(i, n){
        cin >> p[i];
        p[i] /= 100.0;
    }
    forn(i, n)
        cin >> a[i];
    forn(i, nmax)
    forn(j, nmax)
    forn(k, nmax)
        t[i][j][k] = 0;
    t[0][0][k] = 1.0;
    forn(i, n)
        forn(j, nmax)
            forn(k, nmax){
                {
                    t[i+1][j][k] += t[i][j][k] * (1 - p[i]);
                }
                if (a[i] != -1){
                    int nk = min(nmax - 1, k + a[i] + 1);
                    t[i+1][j + 1][nk] += t[i][j][k] * p[i];
                } else 
                    t[i+1][j+1][k] += t[i][j][k] * p[i];
            }
    double res = 0.0;
    for (int j = l; j < nmax; j ++)
        for (int k = j; k < nmax; k ++)
            res += t[n][j][k];
    printf("%0.9lf\n", res);
    

    return 0;
}