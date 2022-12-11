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

const int nmax = 100100;

int n, m, x, y;
pii a[nmax];
pii b[nmax];
vector<pii> res;


int main ()
{
    cin >> n >> m >> x >> y;
    forn(i ,n){
        scanf("%d", &a[i].fs);
        a[i].sc = i;
    }
    forn(i, m){
        scanf("%d", &b[i].fs);
        b[i].sc = i;
    }
    sort(a, a + n);
    sort(b, b + m);
    int pos = 0;
    forn(i, n){
        while (pos < m && a[i].fs - x > b[pos].fs) pos ++;
        if (pos >= m) break;
        if (a[i].fs - x <= b[pos].fs && b[pos].fs <= a[i].fs + y){
            res.pb(mp(a[i].sc, b[pos].sc));
            pos ++;
        }
    }
    cout << res.size() << endl;
    forn(i, res.size())
        printf("%d %d\n", res[i].fs + 1, res[i].sc + 1);



    return 0;
}