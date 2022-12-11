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
typedef pair <long long, long long> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int nmax = 262144 / 2;

int n, m;
vector<pair<pii, int> > t[nmax * 2];
int pos[nmax * 2];
int res[nmax * 2];
int a[nmax], b[nmax];
vector<pair<pii, pii> > e;

void add(int v, int l, int r, int c, pii x, int i){
    if (l > c) return;
    if (r < c) return;
    t[v].pb(mp(x, i));
    if (l == r)
        return;
    int m = (l + r) / 2;
    add(v * 2, l, m, c, x, i);
    add(v * 2 + 1, m + 1, r, c, x, i);      
}

bool ls(pair <pii, int> a, pair <pii, int> b){
    if (a.fs.sc != b.fs.sc)
        return a.fs.sc < b.fs.sc;
    return a.fs.fs < b.fs.fs;
}          

double inter(pii a, pii b){
    return 1.0 * (a.fs - b.fs) / (b.sc - a.sc);
}

void pre_calc(int v, int l, int r){
    pos[v] = 0;
    sort(all(t[v]), ls);
    vector<pair<pii, int> > res;
    forn(i, t[v].size()){
        while (res.size() > 0 && res[res.size()-1].fs.fs <= t[v][i].fs.fs)
            res.pop_back();
        res.pb(t[v][i]);
    }
    vector<pair<pii, int> > g;
    ford(i, res.size()){
        while ((int)g.size() > 1){
            pii l = g[g.size()-1].fs;
            pii p = g[g.size()-2].fs;
            if (-inter(l, p) + inter(res[i].fs, p) > -1e-4)
                g.pop_back(); 
            else
                break;
        }
        g.pb(res[i]);
    }
    reverse(all(g));
    t[v] = g;
    pos[v] = 0;
    if (l == r)
        return;
    int m = (l + r) / 2;
    pre_calc(v * 2, l, m);
    pre_calc(v * 2 + 1, m + 1, r);
}

pair<long long, int> get(int v, int t1, int deb = 0){
    if (deb){
         cerr << pos[v] << endl;
        forn(i, t[v].size())
            cerr << t[v][i].fs.fs << " " << t[v][i].fs.sc << " " << t[v][i].sc << endl;
    }
    
    while (pos[v] < t[v].size() - 1){
        long long f1 = t[v][pos[v]].fs.fs + t[v][pos[v]].fs.sc * t1;
        long long f2 = t[v][pos[v]+1].fs.fs + t[v][pos[v]+1].fs.sc * t1;
        if (f2 >= f1)
            pos[v] ++;
        else
            break;
    }
    long long f1 = t[v][pos[v]].fs.fs + t[v][pos[v]].fs.sc * t1;
    return mp(f1, t[v][pos[v]].sc);
}

pair<long long, int> calc(int v, int l, int r, int l1, int r1, int t1){
    if (l > r1)
        return mp(-1, 0);
    if (r < l1)
        return mp(-1, 0);//
//  if (r == 4 && l == 1 && t1 == 2){
///     get(v, t1, 1);
//      cerr << "here" << endl;
//  }
    if (l1 <= l && r <= r1)
        return get(v, t1);
    int m = (l + r) / 2;
    return max(calc(v * 2, l, m, l1, r1, t1), calc(v * 2 + 1, m + 1, r, l1, r1, t1));
}

int main ()
{
    cin >> n >> m;
    forn(i, n){
        scanf("%d %d", &a[i], &b[i]);
        add(1, 1, nmax, i + 1, mp(a[i], b[i]), i+1);
    }
//  cerr << "here" << endl;
    pre_calc(1, 1, nmax);
//  cerr << "pre_cacl" << endl;
    forn(i, m){
        int l, r, t;
        scanf("%d %d %d", &l, &r, &t);
        e.pb(mp(mp(t, i), mp(l, r)));
    }
    sort(all(e));
    forn(i, e.size()){
        int t = e[i].fs.fs;
        int l = e[i].sc.fs;
        int r = e[i].sc.sc;
        res[e[i].fs.sc] = calc(1, 1, nmax, l, r, t).sc;
    }
    forn(i, m)
        printf("%d\n", res[i]);

    return 0;
}