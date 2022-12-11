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

const int nmax = 140;

int h[nmax][nmax];
int n, t, cnt;

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

inline void add(int x, int y, int n) {
    h[x][y] += n;
}

void push(int x, int y) {
    cnt ++;
    int now = h[x][y] / 4;
    if (now > 0) {
        forn(i, 4)
            add(x + px[i], y + py[i], now);
        h[x][y] -= now * 4;
        forn(i, 4)
            push(x + px[i], y + py[i]);
    }
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> t;
    add(nmax / 2, nmax / 2, n); 
    push(nmax / 2, nmax / 2);

/*  int mx = 0, my = 0;
    forn(i, nmax)
        forn(j, nmax)
            if (h[i][j] > 0) {
                mx = max(mx, i);
                my = max(my, j);
            }   
    cerr << cnt << " " << mx << " " << my << endl;
*/      

    forn(i, t) {
        int x, y;
        scanf("%d %d", &x, &y);
        x += nmax / 2;
        y += nmax / 2;
        if (x < 0 || y < 0 || x >= nmax || y >= nmax)
            cout << 0 << endl;
        else
            cout << h[x][y] << endl;
    }

    return 0;
}