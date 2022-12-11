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

const int nmax = 100100;

int n;
double a, d;
int t[nmax], v[nmax];
double res[nmax];

double calc(double d, double a, double v){
    double t = min(v / a, sqrt(2. * d / a));
    double len = a * t * t / 2.;
    return t + (d - len) / v;
}

int main ()
{
    cin >> n >> a >> d;
    forn(i ,n)
        scanf("%d %d", &t[i], &v[i]);
    forn(i, n){
        res[i] = calc(d, a, v[i]) + t[i];
    }
    res[n] = 1e18;
    for (int i = 1; i < n; i ++)
        res[i] = max(res[i-1], res[i]);
    forn(i, n)
        printf("%0.9lf\n", res[i]);
    return 0;
}