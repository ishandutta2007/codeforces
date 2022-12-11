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
#include <complex>
#include <bitset>

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
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const long double eps = 1e-9;
const int inf = (int)1e9 + 100;//(1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x; }

const int nmax = 100100;

pii a[nmax];
long long deg[150];

int main ()
{
    int n;
    cin >> n;
    forn(i, n)
        scanf("%d %d", &a[i].fs, &a[i].sc);
    deg[0] = 1;
    forn(i, 100)
        deg[i+1] = deg[i] * 4;
    int l = 0, r = 1e9 + 1e7;
    forn(i, n)
        l = max(l, a[i].fs + 1);
    while (l < r) {
        int mid = (l + r) / 2;
        bool done = 1;
        forn(i, n) {
            int d = mid - a[i].fs;
            if (d > 30) continue;
            if (a[i].sc > deg[d]) {
                done = 0;
                break;
            }
        }
        if (done)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;

    return 0;
}