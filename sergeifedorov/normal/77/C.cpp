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

template <class T> T sqr (T x) {return x * x;}

const int nmax = 100100;

int n;
vector<int> g[nmax];
int a[nmax];
bool used[nmax];
long long res[nmax], os[nmax];


long long calc(int v){
    used[v] = 1;
    long long sum = 0 ;
    vector<long long> now;

    forn(i, g[v].size())
        if (!used[g[v][i]]){
            a[g[v][i]] --;
            calc(g[v][i]);
            now.pb(res[g[v][i]] + 2);
            sum += os[g[v][i]];
        }
    sort(all(now));
    ford(i, now.size())
        if (a[v] > 0){
            res[v] += now[i];
            a[v] --;
        }
    res[v] += 2 * min(sum, 1ll * a[v]);
    os[v] = max(0ll, a[v] - sum);
    return res[v];
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n)
        scanf("%d", &a[i]);
    forn(i, n-1){
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int s;
    cin >> s;
    s --;
    memset(used, 0, sizeof used);
    cout << calc(s) << endl;

    return 0;
}