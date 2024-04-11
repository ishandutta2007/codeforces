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

const int n = 8;
int px[] = {-1, 0, 1, 0, 1, 1, -1, -1, 0};
int py[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};

bool check(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

char s[n][n];

void win(){
    puts("WIN");
    exit(0);
}

void go(int nx, int ny, int sx, int sy, int mv){
    if (sx < 0 || mv == n + 1)
        win();
    forn(p, 9){
        int nx1 = nx + px[p];
        int ny1 = ny + py[p];
        int sx1 = sx + px[p];
        int sy1 = sy + py[p];
        if (!check(nx1, ny1))
            continue;
        if (check(sx1, sy1) && s[sx1][sy1] == 'S')
            continue;
        sx1 --;
        if (check(sx1, sy1) && s[sx1][sy1] == 'S')
            continue;
        go(nx1, ny1, sx1, sy1, mv + 1);
    }
}

int main ()
{
    forn(i, n)
        forn(j, n)
            cin >> s[i][j];
    go(n-1, 0, n-1, 0, 0);
    puts("LOSE");

    return 0;
}