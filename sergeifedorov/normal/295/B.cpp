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
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 555;

int n;
int a[nmax][nmax];
int64 d[nmax][nmax];
int x[nmax];
int used[nmax];
int64 res[nmax];

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n;
    forn(i, n)
        forn(j, n)
            cin >> a[i][j];
    forn(i, n) {
        cin >> x[i];
        x[i] --;
    }
    forn(i, n)
        forn(j, n)
            d[i][j] = a[i][j];
    memset(used, 0, sizeof used);
    ford(i, n) {
        int v = x[i];
        used[v] = 1;
        forn(j, n)
            forn(k, n)
                if (used[j] && used[k]) {
                    d[v][j] = min(d[v][j], d[v][k] + d[k][j]);
                }
        forn(j, n)
            forn(k, n)
                if (used[j] && used[k]) {
                    d[j][v] = min(d[j][v], d[j][k] + d[k][v]);
                }
        forn(j, n)
            forn(k, n)
                if (used[j] && used[k]) {
                    d[j][k] = min(d[j][k], d[j][v] + d[v][k]); 
                }
        res[i] = 0;
        forn(j, n)
            forn(k, n)
                if (used[j] && used[k])
                    res[i] += d[j][k];
    }
    forn(i, n)
        cout << res[i] << " ";
    cout << endl;


    return 0;
}