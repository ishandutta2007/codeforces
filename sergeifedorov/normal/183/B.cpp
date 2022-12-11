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
#include <complex>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
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

long long gcd(long long a, long long b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

const int nmax = 1000 * 1001;

typedef pair<long long, long long> point;

struct line{
    long long a,b,c;
    line(){};
    line (long long a1, long long b1, long long c1){
        a = a1; b = b1; c = c1;
        };
    line (point v, point u){
        a = u.y - v.y;
        b = v.x - u.x;
        c = -(v.x * a + v.y * b);
        };
    };

long long side(line l, point a){
    return l.a * a.x + l.b * a.y + l.c;
    }


    int n, m;

int res[nmax];
point p[nmax];



int main ()
{
    cin >> n >> m;
    forn(i, m)
        cin >> p[i].x >> p[i].y;
    forn(i, n)
        res[i + 1] = 1; 
    forn(i, m)
        forn(j, m){
            if (i == j) continue;
            line l(p[i], p[j]);
            int cnt = 0;
            forn(k, m)
                if (side(l, p[k]) == 0)
                    cnt ++;
            int now = 1;
            if (l.c < 0) l.c *= -1, now *= -1;
            if (l.a < 0) l.a *= -1, now *= -1;
            if (l.a == 0) continue;
            if (now == 1) continue;
            if (l.c % l.a != 0) continue;
            if (l.c / l.a > n) continue;
            res[l.c / l.a] = max(res[l.c / l.a], cnt);
    }   
    long long ans = 0;
    forn(i, n)
        ans += res[i+1];
    cout << ans << endl;

    return 0;
}