#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <ctime>
#include <cassert>
#include <complex>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i ++)
#define ford(i,n) for (int j = (int)(n)-1; j >= 0; j --)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define fs first
#define sc second
#define I (int)
#define seta(x,y) memset (x, y, sizeof (x))

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const int inf = (1 << 30) - 1;
const int64 inf64 = (1LL << 62) - 1;
const ldb eps = 1e-9;
const ldb pi = acosl(-1.); 

int n, m;
vector <int> g[1000500];
vector <int> A;
bool u[1000500];
vector <pii> Q;

void go (int v) {
    if (u[v])
        return;
    u[v] = 1;
    A.pb (v);
    forn (i, g[v].size())
        go (g[v][i]);
}

int main ()
{
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);    
    cin >> n >> m;
    forn (i, m) {
        int x, y;
        scanf ("%d%d", &x, &y);
        x --;
        y --;
        g[x].pb (y);
        g[y].pb (x);
    }
    seta (u, 0);
    forn (i, n)
        if (i == 0 || (!u[i] && g[i].size() > 0)) {
            A.clear ();
            go (i);
            int c = 0;
            forn (j, A.size())
                if (g[A[j]].size() % 2 == 1)
                    c ++;
            Q.pb (mp (A.size(), c));
        }
    if (Q.size() == 1 && Q[0].sc == 0) {
        cout << 0 << endl;
        return 0;
    }
    forn (i, Q.size())
        if (Q[i].sc == 0)
            Q[i].sc = 2;
    int sum = 0;
    forn (i, Q.size())
        sum += Q[i].sc;
    cout << sum / 2 << endl;
    return 0;
}