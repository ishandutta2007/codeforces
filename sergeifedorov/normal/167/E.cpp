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

const int nmax = 700;

int n, m, p;
vector<int> g[nmax];
int in[nmax], out[nmax];
int us[nmax][nmax];
long long w[nmax][nmax], dp[nmax][nmax];  
vector<int> s, t;

long long calc(int u, int v){
    if (us[u][v]) return dp[u][v];
    if (u == v) return dp[u][v] = 1;
    dp[u][v] = 0;
    us[u][v] = 1;
    forn(i, g[u].size())
        dp[u][v] = (dp[u][v] + calc(g[u][i], v)) % p;
    return dp[u][v];
}

long long power(long long a, long long b, long long p){
    if (b == 0) return 1;
    a %= p;
    if (p == 1) return a % p;
    long long res = power((a * a) % p, b / 2, p);
    if (b & 1)
        res = (res * a) % p;
    return res;
}

int main ()
{
    cin >> n >> m >> p;
    forn(i, m){
        int u, v;
        scanf("%d %d", &u, &v);
        u --; v--;
        g[u].pb(v);
        out[u] ++;
        in[v] ++;
    }
    memset(us, 0, sizeof us);
    forn(v, n){
        if (in[v] == 0)
            s.pb(v);
        if (out[v] == 0)
            t.pb(v);
    }
    forn(i, s.size())
        forn(j, t.size())
            w[i][j] = calc(s[i], t[j]);


    long long res = 1;
    int k = s.size();
/*
    forn(i, k){
        forn(j, k)
            cerr << w[i][j] << " ";
        cerr << endl;
    }
*/
    forn(i, k){
        int pos = -1;
        for (int j = i; j < k; j ++)
            if (w[j][i] > 0)
                pos = j;
        if (pos == -1) {
            res = 0;
            break;
        }
        if (pos != i){
            res = (-res + p) % p;
            for (int j = 0; j < k; j ++)
                swap(w[i][j], w[pos][j]);
        }
        for (int j = i + 1; j < k; j ++){
            long long now = (power(w[i][i], p - 2, p) * w[j][i]) % p;
            for (int l = i; l < k; l ++)
                w[j][l] = ((w[j][l] - w[i][l] * now) % p + p)%p;
        }
        res = (res * w[i][i]) % p;
    }
    cout << res << endl;
    

    return 0;
}