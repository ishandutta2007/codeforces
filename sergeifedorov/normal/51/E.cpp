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

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int nmax = 700;

int n, m;
bitset<nmax> g[nmax];
bitset<nmax> w[nmax][nmax];
bitset<nmax> a, b, c;
int f[nmax][nmax];
long long res;
long long s[nmax];

int main ()
{

    cin >> n >> m;
    forn(i, m){
        int u, v;
        scanf("%d %d", &v, &u);
        v --;
        u --;
        g[u][v] = g[v][u] = 1;
        s[v] ++;
        s[u] ++;
    }
    forn(i, n)
        forn(j, n){
            w[i][j] = g[i] & g[j];
            w[i][j][i] = w[i][j][j] = 0;
            f[i][j] = w[i][j].count();
        }   
    long long q = 0;
    forn(i, n)
        forn(j, n)
            if (g[i][j])
                q = q + (s[i] - 2) * f[i][j];
    q /= 2;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (g[i][j])
                for (int k = 0; k < n; k++)
                    if (j != k && i != k) 
                        res = res + (f[i][k] - w[i][k][j]) * (f[j][k] - w[j][k][i]);
    }
    res = (res - 2 * q) / 10;
    cout << res << endl;
    return 0;

    n = 700;
    m = n * (n-1) / 2;
    cout << n << " " << m << endl;
    forn(i, n)
        forn(j, n)
            if (j > i)
                printf("%d %d\n", i + 1, j + 1);

    
    return 0;
}