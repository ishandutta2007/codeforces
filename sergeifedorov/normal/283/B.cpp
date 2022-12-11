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

const int nmax =262144;

int n;
int a[nmax], a1[nmax];
int64 used[nmax], mv[nmax], res[nmax];

int step;

int64 calc(int v) {
    if (v == 0) return -1e18;
    if (used[v] == step) return -1e18;
    if (used[v] < step && used[v] > 0) return res[v];
    used[v] = step;
    res[v] = mv[v] + calc(a[v]);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n - 1) {
        scanf("%d", &a1[i + 1]);
        a[i+1] = a1[i+1];
    }   

    forn(i, n)
        used[i] = 0;

    for (int i = 1; i < n; i ++) {
        int x = i + a[i];
        mv[i] += a[i];
        if (x < 0 || x >= n) {
            res[i] = mv[i];
            used[i] = 1;
            continue;
        }
        mv[i] += a[x];
        x -= a[x];
        if (x < 0 || x >= n) {
            res[i] = mv[i];
            used[i] = 1;
            continue;
        }
        a[i] = x;
    }

    step = 2;

    for (int i = 1; i < n; i ++) {
        step ++;
        if (used[i] == 0)
            calc(i);
    }

    res[0] = -1e18;
    for (int i = 1; i < n; i ++) {
        int64 now = 0;
        {
            int x = 0;
            {
                now += i;
                x += i;
                now += a1[x];
                x -= a1[x];
                if (x >= 0 && x < n)
                    now += res[x];
            }
        }
        if (now < -1e17)
            now = -1;
        printf("%I64d\n", now);
    }

    return 0;
}