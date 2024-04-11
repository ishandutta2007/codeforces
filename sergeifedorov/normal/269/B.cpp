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

const int nmax = 5100;

int n, m;
int c[nmax];
double x[nmax];
int t[nmax][nmax], cnt[nmax][nmax];

void go(int i, int j, int res) {
    if (t[i][j] < 0 || t[i][j] > res)
        t[i][j] = res;
}

int main ()
{
    cin >> n >> m;
    forn(i, n) {
        scanf("%d %lf", &c[i], &x[i]);
        c[i] --;
    }
    memset(t, 255, sizeof t);
    t[0][0] = 0;
    forn(i, m) {
        cnt[i][n] = 0;
        ford(j, n)  {
            cnt[i][j] = cnt[i][j + 1];
            if (c[j] == i) cnt[i][j] ++;
        }
    }
    forn(i, n+1)
        forn(j, m)
            if (t[i][j] >= 0) {
//              cerr << i << " " << j << " " << t[i][j] << " " << cnt[i][j] << endl;
                if (c[i] <= j)
                    go(i + 1, j, t[i][j]);
                go (i, j + 1, cnt[j][i] + t[i][j]);
                go (i + 1, j, t[i][j] + 1);
            }
    cout << t[n][m-1] << endl;
    return 0;
}