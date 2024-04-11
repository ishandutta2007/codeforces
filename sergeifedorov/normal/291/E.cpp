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

const int nmax = 300300;

int n, val, res;
string s[nmax];
int p[nmax];
vector<int> g[nmax];
int f[nmax], nxt[nmax][27];
char cur[nmax];
char buf[nmax];

void add(int n, char ch) {
    cur[n] = ch;
    if (n == 0) 
        f[n] = 0;
    else
        f[n] = nxt[n-1][ch-'a'];
    if (f[n] == val) res ++; 
    for (int i = 0; i < 27; i ++)
        if (cur[f[n]] == 'a' + i)
            nxt[n][i] = f[n] + 1;
        else
            if (f[n] != 0)
                nxt[n][i] = nxt[f[n]-1][i];
            else
                nxt[n][i] = 0;
}

void go(int v, int n) {
    forn(i, s[v].size()) {
        add(n, s[v][i]);
        n ++;
    }
    forn(i, g[v].size())
        go(g[v][i], n);
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n - 1) {
        scanf("%d", &p[i+1]);
        p[i+1] --;
        g[p[i+1]].pb(i + 1);
        scanf("%s", buf);
        s[i+1] = buf;
    }   
    scanf("%s", buf);
    s[0] = buf;
    char now = 'z' + 1;
    s[0] += now;
    val = s[0].size() - 1;
    go(0, 0);
    cout << res << endl;

    return 0;
}