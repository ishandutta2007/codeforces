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

const int nmax = 1100;

int a[nmax];
int t[nmax][nmax], p[nmax][nmax];
int n;
vector<pii> res;

inline void go(int &a, int b, int &p, int pr){
    if (a == -1 || a > b){
        a = b;
        p = pr;
    }
}

void go(int n, int j){
    if (n == 0)
        return;
    int pr = p[n][j];
    if (j == pr)
        res.pb(mp(n-1, n));
    if (j == n-1)
        res.pb(mp(pr, n));
    if (j == n)
        res.pb(mp(n-1, pr));
    go(n - 2, pr);
}

int main ()
{
    cin >> n;
    forn(i, n)
        cin >> a[i];
    memset(t, 255, sizeof t);
    int re = -1, pos = -1;
    t[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (t[i][j] >= 0){
            if (i + 1 >= n){
                go(re, t[i][j] + a[j], pos, j);
                continue;;
            }
            if (i + 2 >= n){
                go(re, t[i][j] + max(a[j], a[i+1]), pos, j);
                continue;
            }
            go(t[i+2][j], t[i][j] + max(a[i+1], a[i+2]), p[i+2][j], j);
            go(t[i+2][i+1], t[i][j] + max(a[i+2], a[j]), p[i+2][i+1],j);
            go(t[i+2][i+2], t[i][j] + max(a[i+1], a[j]), p[i+2][i+2],j);
        }
    cout << re << endl;
    if (n % 2 == 0){
        res.pb(mp(n-1, pos));
        go(n - 2, pos);
    }else{
        res.pb(mp(pos, pos));
        go(n-1, pos);
    }
    ford(i, res.size()){
        if (res[i].fs == res[i].sc)
            cout << res[i].fs+1 << endl;
        else
        cout << res[i].fs+1 << " " << res[i].sc+1 << endl;
    }


        return 0;
}