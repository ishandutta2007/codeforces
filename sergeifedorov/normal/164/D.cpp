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
#define x first
#define y second
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

long long gcd(long long a, long long b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

pii operator - (pii a, pii b){
    return mp(a.x - b.x, a.y - b.y);
}

pii operator + (pii a, pii b){
    return mp(a.x + b.x, a.y + b.y);
}

long long dist(pii a, pii b){
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

const int nmax = 1010;

pii p[nmax];
int n, k, m;
pair<long long, pii> e[nmax * nmax];

pii die[nmax * 40];
int res[nmax];
int ord[nmax];
vector<int> g[nmax];
int cnt;
int deg[nmax];
set<pii> alive;

void kill(int v){
//  cout << "kill " << v << " " << res[v] << endl;
    res[v] = 1;
    alive.erase(mp(-deg[v], v));
    forn(i, g[v].size()){
        int u = g[v][i];
        if (alive.count(mp(-deg[u], u))){
            alive.erase(mp(-deg[u], u));
            deg[u] --;
            if (deg[u] > 0)
                alive.insert(mp(-deg[u], u));
        }
    }
}

void rekill(int v){
//  cout << "rekill " << v << endl;
    res[v] = 0;
    forn(i, g[v].size()){
        int u = g[v][i];
        if (alive.count(mp(-deg[u], u)) || deg[u] == 0){
            alive.erase(mp(-deg[u], u));
            deg[u] ++;
            alive.insert(mp(-deg[u], u));
        }
    }
    alive.insert(mp(-deg[v], v));
}

bool go(int kl){
    if (kl > k) return 0;
    if (alive.size() == 0) return 1;
    pii now = *alive.begin();
    int v = now.sc;

    if (alive.size() / (-now.fs + 1) + kl > k)
        return 0;

    if (now.fs == -1){
        int w = alive.size();
        assert(w % 2 == 0);
        if (kl + w / 2 > k)
            return 0;
        while (alive.size() > 0){
            pii now = *alive.begin();
            kill(now.sc);
            kl ++;
        }
        assert(kl <= k);
        return 1;
    }
    
    if (kl + deg[v] <= k){
        vector<int> buf;
        int nkl = kl;
        forn(i, g[v].size())
            if (res[g[v][i]] == 0){
                 buf.pb(g[v][i]);
                 kill(g[v][i]);
                 nkl ++;
            }
        
        if (go(nkl))
            return 1;
        ford(i, buf.size())
            rekill(buf[i]);
    }
    if (kl + 1 <= k){
        kill(v);
        if (go(kl + 1))
            return 1;
        rekill(v);
    }
    return 0;
}

bool check(int st){
    st ++;
    int e1 = 0;
    for (int i = st; i < m; i ++)
        die[e1++] = e[i].sc;
    forn(i, n)
        g[i].clear();
    forn(i, e1){
        g[die[i].fs].pb(die[i].sc);
        g[die[i].sc].pb(die[i].fs);
//      cerr << die[i].fs << " " << die[i].sc << endl;
    }
    forn(i, n)
        deg[i] = g[i].size();
    alive.clear();
    forn(i, n)
        if (deg[i] > 0)
            alive.insert(mp(-deg[i], i));
    memset(res, 0, sizeof res);
    return go(0);
/*  
    vector<pii> buf;
    forn(i, n)
        if (g[i].size() > 0)
            buf.pb(mp(-g[i].size(), i));
    sort(all(buf));
    forn(i, buf.size())
        ord[i] = buf[i].sc;
    cnt = buf.size();
//  forn(i, ord.size())
//      cerr << ord[i] << " ";
//  cerr << endl;           
    memset(res, 0, sizeof res);
    return go(0, 0);*/
}

int main ()
{
    cin >> n >> k;
    forn(i, n)
        scanf("%d %d", &p[i].x, &p[i].y);

/*  n = 1000;
    k = 30;
    forn(i, n){
        p[i].x = 0;// % 30;//rand() % 50;
        p[i].y = i;// / 30;//rand() % 50;
    }
*/  
    m = 0;
    forn(i, n)
        for (int j = i + 1; j < n; j ++)
            e[m++] = mp(dist(p[i], p[j]), mp(i, j));
    sort(e, e + m);
    int r = m - 1, l = max(0, r - n * k);
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    check(l);


    vector<int> buf;
    forn(i, n)
        if (res[i] > 0)
            res[i] = 1;
        else
            buf.pb(i);
    while (buf.size() > n - k){
        res[buf.back()] = 1;
        buf.pop_back();
    }
    forn(i, n)
        if (res[i])
            cout << i + 1 << " ";
    cout << endl;

    return 0;
}