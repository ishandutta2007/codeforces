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

const int nmax = 1000 * 1001;
const int vmax = nmax / 7;

map<int, int> nxt[vmax];
vector<pii> g[nmax];
int p[vmax];
char buf[nmax];
string s;
int sz;
string sp[201];
int a[201];
int m;
int step;
int cnt[vmax];

int hash(string w){
    int res = 0;
    forn(i, w.size())
        res = res * 239017 + w[i];
    return res;
}

int next(int now, string w){
    int hsh = hash(w);
    if (!nxt[now].count(hsh)){
        nxt[now][hsh] = sz;
        p[sz] = now;
        g[now].pb(mp(hsh, sz));
        sz ++;
    }
    cnt[nxt[now][hsh]] ++;
    return nxt[now][hsh];
}

long long calc(int v, int pos){
    long long res = 0;
    forn(i, g[v].size())
        if (g[v][i].fs == a[pos])
            res += (pos == m-1 ? cnt[g[v][i].sc] + calc(g[v][i].sc, pos) : calc(g[v][i].sc, pos + 1));
        else
            res += calc(g[v][i].sc, pos);
    return res;
}

void solve(){
    gets(buf);
    s = buf;
    s = s + " ";
    m = 0;
    string now = "";
    forn(i, s.size()){
        if (s[i] == ' '){
            if (now.size() > 0)
                sp[m++] = now;
            now = "";
            continue;
        }
        now += s[i];
    }
    forn(i, m)
        a[i] = hash(sp[i]);
    cout << calc(0, 0) << endl;
}

int main ()
{
    gets(buf);
    s = buf;
    int now = 0;
    sz = 1;
    forn(i, s.size()){
        assert(s[i] == '<'); i ++;
        if (s[i] == '/'){
            while (s[i] != '>') i ++;
            now = p[now];
            continue;
        }
        string w ="";
        while (s[i] != '>'){
            w += s[i];
            i ++;
        }
        if (w[w.size() - 1] == '/'){
            w = w.substr(0, w.size() - 1);
            now = next(now, w);
            now = p[now];
            continue;
        } else
            now = next(now, w);
    }
//  cerr << now << endl;
        
    int n;
    scanf("%d", &n);
    gets(buf);
    forn(i, n)
        solve();

    cerr << clock() << endl;        
    return 0;
}