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

template <class T> T sqr (T x) {return x * x;}
                                                                        
double r1, r2, k;


long double ang(pair<long double,long double> a, pair<long double,long double> b){
    long double res = a.fs * b.sc - a.sc * b.fs;
    res = fabsl(res);
    res /= sqrt(sqr(a.fs) + sqr(a.sc));
    res /= sqrt(sqr(b.fs) + sqr(b.sc));
    return res;
}

void ret(pair<long double,long double> &a, long double r){
    long double len = sqr(r) / sqrt(sqr(a.fs) + sqr(a.sc));
    long double now = len * len / sqr(r);// sqrt(sqr(a.fs) + sqr(a.sc)) / sqr(r);
    a.fs *= now;
    a.sc *= now;
}

void write(pair<long double,long double> a, pair<long double,long double> b, pair<long double,long double> c){
    b.fs -= a.fs;
    b.sc -= a.sc;
    c.fs -= a.fs;
    c.sc -= a.sc;
    long double r = sqrt(sqr(b.fs - c.fs) + sqr(b.sc - c.sc)) / (2 * ang(b,c));
    printf("%0.9lf\n", (double)r);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    int tst;
    cin >> tst;
    forn(i, tst){
        cin >> r1 >> r2 >> k;
        pair<long double, long double> p1, p2, p3;
        p1 = mp(2 * r1, 0);
        p2 = mp(2 * r2 * sqr(2 * r1) / sqr(2 * r2), 0);
        long double r3 = (p1.fs - p2.fs) / 2.0;
        r3 = fabsl(r3);
        p3 = mp((p1.fs + p2.fs) / 2.0, r3);

        p1.sc += r3 * 2 * k;
        p2.sc += r3 * 2 * k;
        p3.sc += r3 * 2 * k;
        ret(p1, 2 * r1);
        ret(p2, 2 * r1);
        ret(p3, 2 * r1);
        write(p1, p2, p3);
    }


    return 0;
}