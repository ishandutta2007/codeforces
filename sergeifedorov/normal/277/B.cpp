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
#define x first
#define y second
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


struct line{
    long long a,b,c;
    line(){};
    line (long long a1, long long b1, long long c1){
        a = a1; b = b1; c = c1;
        };
    line (pii v, pii u){
        a = u.y - v.y;
        b = v.x - u.x;
        c = -(v.x * a + v.y * b);
        };
    };

long long side(line l, pii a){
    return l.a * a.x + l.b * a.y + l.c;
    }


vector<pii> gen(int n, double r, double st = 0) {
    vector<pii> res;
    double alph = 2 * pi / n;
    forn(i, n) {
        double now = st + alph * i;
        int x = r * cos(now);
        int y = r * sin(now);
        res.pb(mp(x, y));
    }
    return res;
}

int gen() {
    int mod = 1e8 - 1e7;
    return abs((rand() << 16) | rand()) % (mod * 2) - mod;
}

//pii gen() {
//  return mp(gen(), gen());
//}

void no() {
    puts("-1");
    exit(0);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    int n, m;
    cin >> n >> m;

    if (n > 2 * m) no();
    if (m == 3 && n > 4) no();


    vector<pii> a = gen(m, 1e7);
    vector<pii> b = gen(m, 1e6, pi / 150);
    forn(i, a.size())
        cout << a[i].fs << " " << a[i].sc << endl;
    forn(i, n - m)
        cout << b[i].fs << " " << b[i].sc << endl;
        

    return 0;
}