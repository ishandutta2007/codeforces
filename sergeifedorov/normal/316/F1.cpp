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

const int nmax = 1700;

int px[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int py[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int n, m;
int a[nmax][nmax];
vector<pii> now;

int dfs(int x, int y, int c1, int c2, int d) {
    int res = 1;
    now.pb(mp(x, y));
    a[x][y] = c2;
    for (int i = -d; i <= d; i ++)
    for (int j = -d; j <= d; j ++) {
        int nx = x + i;
        int ny = y + j;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == c1)
            res += dfs(nx, ny, c1, c2, d);
    }
    return res;
}

int get(int x, int y, int c) {
    int res = 0;
    forn(i, 9) {
        int nx = x + px[i];
        int ny = y + py[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == c)
            res ++;
    }   
    return res;
}

void write() {
    return;
    forn(i, n) {
        forn(j, m) 
            cout << a[i][j];
        cout << endl;
    }
}

bool check(int x, int y) {
    int res = 0;
    for (int i = -2; i <= 2; i ++)
    for (int j = -2; j <= 2; j ++) {
        int nx = x + i;
        int ny = y + j;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            if (a[nx][ny] == 2)
                res --;
            if (a[nx][ny] == 3)
                res ++;
        }
    }
    return res > 0;
}

int calc() {
    vector<pii> kl, w;
    forn(i, now.size()) {
        int x = now[i].fs;
        int y = now[i].sc;
        int e = get(x, y, 2);
        if (e < 9)
            kl.pb(mp(x, y));
    }
    forn(i, kl.size()) {
        int x = kl[i].fs;
        int y = kl[i].sc;
        a[x][y] = 3;
    }
    forn(i, now.size()) {
        int x = now[i].fs;
        int y = now[i].sc;
        if (a[x][y] == 3) continue;
        if (check(x, y))
            w.pb(mp(x, y));
/*      int e = get(x, y, 3);
        int q = get(x, y, 2);
        if (e > 2 && q < 3)
            w.pb(mp(x, y));*/
    }
    forn(i, w.size()) {
        int x = w[i].fs;
        int y = w[i].sc;
        a[x][y] = 5;
    }
    write();
    int res = 0;
    forn(i, w.size()) {
        int x = w[i].fs;
        int y = w[i].sc;
        if (a[x][y] == 5) {
            int w = dfs(x, y, 5, 6, 2);
            if (w > 4)
                res ++;
        }
    }
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> m;
    forn(i, n)
        forn(j, m) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    vector<int> res;
        forn(i, n)
            forn(j, n)
                if (a[i][j] == 1) {
                    now.clear();
                    dfs(i, j, 1, 2, 2);
                    res.pb(calc());
                }
        sort(all(res));
        cout << res.size() << endl;
        forn(i, res.size())
            cout << res[i] << " ";
        cout << endl;
    return 0;
}