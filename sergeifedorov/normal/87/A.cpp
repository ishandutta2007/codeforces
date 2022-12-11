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


int64 gcd(int64 a, int64 b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

int64 next(int64 now, int64 a){
    if (now % a == 0) return now;
    int64 q = now / a;
    return (q + 1) * a;
}


int main ()
{
    int64 a,b;
    cin >> a >> b;
    //int64 c = gcd(a, b);
//  a /= c;
//  b /= c;
    int64 ra, rb;
    ra = rb = 0;
    int64 now = 1;
    while (now <= a * b){
        int64 na = next(now, a);
        int64 nb = next(now, b);
        if ((na == nb && a > b) || (na < nb))
            ra += na - now + 1;
        else
            rb += nb - now + 1;
        now = min(na, nb) + 1;
    }
    if (ra > rb)
        puts("Dasha");
    if (ra == rb)
        puts("Equal");
    if (ra < rb)
        puts("Masha");
        return 0;
}