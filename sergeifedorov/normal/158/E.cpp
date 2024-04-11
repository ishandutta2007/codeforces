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

const int nmax = 4100;
const int MAX = 86400;

int n, k, res;
pii e[nmax];
int t[nmax][nmax];

inline int calc(int st, pii cl){
    return max(st, cl.fs) + cl.sc;
}

int main ()
{
    cin >> n >> k;
    forn(i, n)
        scanf("%d %d", &e[i].fs, &e[i].sc);
    sort(e, e + n);
    forn(i, n + 1)
        forn(j, n + 1)
            t[i][j] = inf;
    for (int i = 0; i <= n; i ++){
        t[0][i] = 1;
        int lst = MAX + 1;
        if (k - i < n)
            lst = min(lst, e[k - i].fs);
        res = max(res, lst - t[0][i]);
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= min(i + 1, k); j ++){
            t[i][j] = calc(t[i-1][j], e[i-1]);
            if (j > 0) t[i][j] = min(t[i][j], t[i-1][j-1]);
            int lst = MAX + 1;
            if (i + k - j < n)
                lst = min(lst, e[i + k - j].fs);
            res = max(res, lst - t[i][j]);
        }

    cout << res << endl;

    return 0;
}