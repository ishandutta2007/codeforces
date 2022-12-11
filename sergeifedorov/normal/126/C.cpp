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


const int nmax = 2100;

int a[nmax][nmax];
char s[nmax][nmax];
int n, res;
int x[nmax], y[nmax];


int main ()
{
    int n;
    cin >> n;
    gets(s[0]);
    forn(i, n)
        gets(s[i]);
    forn(i, n)
        forn(j, n)
            a[i][j] = s[i][j] - '0';
    int res = 0;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; i + j < n; j++){
            int now = a[i + j][j] + x[i + j] + y[j];
            now = now & 1;
            if (now){
                res ++;
                x[i + j] ++;
                y[j] ++;
               }
        }
    }
    forn(i, n)
        a[i][i] = (a[i][i] + x[i] + y[i]) & 1;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; i + j < n; j++){
            int now = a[j][i + j] + x[j] + y[i + j];
            now = now & 1;
            if (now){
                res ++;
                y[i + j] ++;
                x[j] ++;
               }
        }
    }
    forn(i, n)
        a[i][i] = (a[i][i] + x[i] + y[i]) & 1;
    forn(i ,n)
        if (a[i][i] == 1)
            res ++;
    cout << res << endl;
            


            

    return 0;
}