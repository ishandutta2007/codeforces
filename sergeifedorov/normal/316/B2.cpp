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

const int nmax = 5000;

int n, x;
int us[nmax], g[nmax], p[nmax], can[nmax];

int go(int v) {
    int res = 0;
    int now = v;
    while(now >= 0) {
        us[now] = 1;
        res ++;
        now = g[now];
    }
    now = v;
    while(now >= 0) {
        us[now] = 1;
        now = p[now];
    }
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> x;
    x --;
    memset(p, 255, sizeof p);
    forn(i, n) {
        cin >> g[i];
        g[i] --;
        if (g[i] >= 0) {
            us[g[i]] = 1;
            p[g[i]] = i;
        }
    }
    int st = go(x);
    can[st] = 1;
    forn(i, n)
        if (!us[i]) {
            int now = go(i);
            ford(j, n + 1)
                if (can[j])
                    can[j + now] = 1;
        }
    forn(j, n + 1)
        if (can[j])
            cout << j << endl;

    return 0;
}