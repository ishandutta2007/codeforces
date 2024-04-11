#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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

int n, m, a, b, c;
int f[100][100];
bool u[26];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void answer (string s)
{
    cout << s << endl;
    exit (0);
}

void paint (vector <pii> &a)
{
    seta (u, 0);
    forn (i, a.size())
        forn (j, 4)
        {
            int x = a[i].fs + dx[j];
            int y = a[i].sc + dy[j];
            if (0 <= x && x < n && 0 <= y && y < m)
                if ('a' <= f[x][y] && f[x][y] <= 'z')
                    u[f[x][y] - 'a'] = 1;
        }
    int p = 0;
    while (u[p])
        p ++;
    forn (i, a.size())
        f[a[i].fs][a[i].sc] = p + 'a';
    a.clear ();
}

int main ()
{
//  freopen ("input.txt", "r", stdin);
//  freopen ("output.txt", "w", stdout);
    cin >> n >> m >> a >> b >> c;
    seta (f, 0);
    if (n % 2 && m % 2)
        answer ("IMPOSSIBLE");
    if (n % 2)
    {
        vector <pii> tmp;
        for (int i = 0; i < m; i += 2)
        {
            tmp.clear ();
            tmp.pb (mp (0, i));
            tmp.pb (mp (0, i+1));
            a --;
            paint (tmp);
        }
        if (a < 0)
            answer ("IMPOSSIBLE");
    }
    if (m % 2)
    {
        vector <pii> tmp;
        for (int i = 0; i < n; i += 2)
        {
            tmp.clear ();
            tmp.pb (mp (i, 0));
            tmp.pb (mp (i+1, 0));
            b --;
            paint (tmp);
        }
        if (b < 0)
            answer ("IMPOSSIBLE");
    }
    forn (i, n)
        forn (j, m)
            if (f[i][j] == 0)
            {
                vector <pii> tmp;
                tmp.pb (mp (i, j));
                if (c > 0)
                {
                    tmp.pb (mp (i+1, j));
                    tmp.pb (mp (i, j+1));
                    tmp.pb (mp (i+1, j+1));
                    paint (tmp);
                    c --;
                }
                else
                if (a > 1)
                {
                    tmp.pb (mp (i, j+1));
                    paint (tmp);
                    tmp.pb (mp (i+1, j));
                    tmp.pb (mp (i+1, j+1));
                    paint (tmp);
                    a -= 2;
                }
                else
                if (b > 1)
                {
                    tmp.pb (mp (i+1, j));
                    paint (tmp);
                    tmp.pb (mp (i, j+1));
                    tmp.pb (mp (i+1, j+1));
                    paint (tmp);
                    b -= 2;
                }
                else
                    answer ("IMPOSSIBLE");
            }
    forn (i, n)
    {
        forn (j, m)
            printf ("%c", f[i][j]);
        printf ("\n");
    }
    return 0;
}