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
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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

const int nmax = 300300;

int n;
double a[nmax];

int main ()
{
//  freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);

    scanf("%d", &n);
    forn(i,n)
        scanf("%lf", &a[i]);
    sort(a, a + n);
    double l, r;
    l = 0, r = 1e10;
    forn(i, 100){
        double m = (l + r) / 2;             
        double now = a[0]-1;
        int res = 0;
        forn(j, n)
            if (a[j] > now){
                res ++;
                now = a[j] + m * 2;
            }
        if (res <= 3) r = m;
        else l = m;
    }
    printf("%0.9lf\n", l);
        double now = a[0]-1;
    vector<double> w;
        forn(j, n){
            if (a[j] > now){
                w.pb(a[j] + l);
                now = a[j] + l * 2;
            }
        }
    while (w.size() < 3)w.pb(0);
    sort(all(w));
    forn(i, w.size())
        printf("%0.9lf ", w[i]);
    puts("");   
        


    
    
    return 0;
}