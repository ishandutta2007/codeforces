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
typedef pair <double, double> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}
                          
double calc(pii a, pii b) {
     return abs(a.fs * b.sc - a.sc * b.fs);
} 
    
double calc(double w, double h, double al) {
    pii a(w / 2, w / 2 * tan(al / 2));
    pii b(w / 2 - tan(al) * (h - w * tan(al / 2)) / 2, h / 2);
    return calc(a, b) / 2;
}

double calc2(double w, double h, double al) {
    double a = w / 2 * tan(al / 2);
    double b = w * w / 4 / a;
//  cerr << a << " " << b << endl;
    return (a + b) * w; 
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    double w, h, al;

    cin >> w >> h >> al;

    if (al >= 90)
        al = 180 - al;
    if (h < w) swap(w, h);

    al = al * pi / 180.;

    double res = 0;

//  cerr << tan(al) << " " << w / h  << endl;

    if (tan(al / 2) > w / h - eps)
        res = calc2(w, h, al);
    else
        res = (calc(w, h, al) + calc(h, w, al)) * 4;

    printf("%0.9lf\n", res);


    return 0;
}