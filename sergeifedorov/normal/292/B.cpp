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

const int nmax = 100100;

int n, m;
vector<int> g[nmax];

bool bus() {
    forn(i, n)
        if (g[i].size() > 2) return 0;
    int c[3];
    c[0] = c[1] = c[2] = 0;
    forn(i, n)
        c[g[i].size()] ++;
    if (c[1] == 2) return 1;
    return 0;
}

bool ring() {
    forn(i, n)
        if (g[i].size() != 2) return 0;
    return 1;
}

bool star() {
    int a, b;
    a = b = 0;
    forn(i, n) {
        if (g[i].size() == 1) a ++;
        else
        if (g[i].size() == n-1) b ++;
        else return 0;
    }
    if (b == 1) return 1;
    return 0;
}


int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> m;
    forn(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        u --;
        v --;
        g[u].pb(v);
        g[v].pb(u);
    }

    if (bus())
        puts("bus topology");
    else if (ring())
        puts("ring topology");
    else if (star())
        puts("star topology");
    else
        puts("unknown topology");
        
    

    return 0;
}