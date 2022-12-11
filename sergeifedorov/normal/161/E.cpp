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

const int nmax = 100100;

int used[nmax];
vector<int> g[10];
int n, m;
string s[nmax];
int pr[nmax][10];
int res[nmax];
string mat[6];
int CUR;

int st[nmax][6];
vector<pair<string, int> > what[6];

void go(int pos){
    if (pos == m){
        CUR ++;
        return;
    }
    int now = 0;
    forn(j, pos)
        now = now * 10 + mat[pos][j] - '0';
    for (int i = st[now][pos]; i < n; i ++){
        if (pr[i][pos] > now)
            break;
        if (pos == m-1){
            CUR ++;
            continue;
        }
        for (int j = pos; j < s[i].size(); j ++)
            mat[pos][j] = mat[j][pos] = s[i][j];
        go(pos + 1);
    }
}

int solve(string s){
    forn(i, s.size())
        mat[i] = s;
    forn(i, s.size())
        mat[0][i] = mat[i][0] = s[i];
    CUR = 0;
    go(1);
    return CUR;
}

void add(int a){
    int len = 0, v = a;
    while (v > 0){
        len ++;
        v /= 10;
    }
    for (int i = len; i <= 5; i ++)
        g[i].pb(a);
}

void pre_calc(int len){
    sort(all(g[len]));
    n = g[len].size();
    m = len;
    forn(i, n){
        int now = g[len][i];
        s[i] = "";
        forn(j, len)
            s[i] += "0";
        ford(j, len){
            s[i][j] = now % 10 + '0';
            now /= 10;
        }
        forn(j, len + 1)
            pr[i][j] = atoi(s[i].substr(0, j).data());
    }
    s[n] = "999999";
    s[n][0] ++;

    for (int j = 0; j <= 5; j ++){
        int now = 0;
        for (int i = 0; i < nmax; i ++){
            while (pr[now][j] < i)
                now ++;
            st[i][j] = now;
        }
    }

    forn(i, what[len].size()){
        res[what[len][i].sc] = solve(what[len][i].fs);
    }
/*
    forn(i, g[len].size())
        if (res[g[len][i]] == -1){
            res[g[len][i]] = solve(s[i]);
            if (len == 5)
                cerr << i << " " << g[len].size() << " " << res[g[len][i]] << endl;
        }  */
}

int main ()
{                
    //freopen("log22.txt", "w", stdout);
    memset(used, 0, sizeof used);
    used[0] = used[1] = 1;
    for (int i = 2; i < nmax; i ++)
        if (!used[i]){
            add(i);
            for (int j = 2 * i; j < nmax; j += i)
                used[j] = 1;
        }
    int tst;
    cin >> tst;
    forn(i, tst){
        string s;
        cin >> s;
        what[s.size()].pb(mp(s, i));
    }

    memset(res, 255, sizeof res);
    for (int i = 1; i <= 5; i ++){
        if (g[i].size() == 0)
            continue;
//      cerr << "calcing " << i << endl;
        pre_calc(i);
    }
    forn(i, tst)
        cout << res[i] << endl;
    cerr << clock() << endl;
    return 0;
    forn(i, 30)
        cout << g[5][1500 + rand() % (g[5].size()-1500)] << endl;
/*  forn(i, nmax)
        if (res[i] != -1)
            printf("res[%d] = %d;\n", i, res[i]);
*/

    cerr << clock() << endl;
    return 0;
}