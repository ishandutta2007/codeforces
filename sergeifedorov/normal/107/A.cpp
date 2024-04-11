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

const int nmax = 10010;

bool used[nmax];
vector<pii> g[nmax];
int n, m, p;
int s[nmax], t[nmax], w[nmax], in[nmax];

void go(int v, int c, int p){
//  if (used[v])
//      return;
//  used[v] = 1;
//  cerr << v << " " << g[v][0].fs << endl;
    if (g[v].size() == 0){
        s[m] = p;
        t[m] = v;
        w[m] = c;
        m ++;
        return;
    }
    go (g[v][0].fs, min(c, g[v][0].sc), p);
}

int main ()
{
    cin >> n >> p;
    forn (i, p){
        int a,b ,c;
        cin >> a >> b >> c;
        a --;
        b --;
        in[b] ++;        
        g[a].pb(mp(b,c));
    }
    forn (i, n)
        if (in[i] == 0 && g[i].size() > 0)
            go(i, 1e9, i);
    cout << m << endl;
    forn(i, m)
        cout << s[i]+1 << " " << t[i]+1 << " " << w[i] << endl;


    return 0;
}