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

const int P = (int)1e9+7;

const int nmax = 3000;

char buf[110];

int res[110][nmax];

void solve(){
    gets(buf);
    int n = strlen(buf);
    int sum = 0;
    forn(i, n-1)
        sum += buf[i] - 'a';
    int ans = 0;
    for (int i = sum - ('z' - buf[n-1]); i <= sum + (buf[n-1] - 'a'); i ++){
//          cerr << i << endl;
        if (i >= 0){
            ans = ans + res[n-1][i];
            if (ans >= P)
                ans -= P;
      }
     }
        printf("%d\n", ans - 1);
}

int main ()
{
     int tst;
     cin >> tst;
     gets(buf);
     
     res[0][0] = 1;
     forn(i, 100)
        forn(j, nmax)
            forn(k, 26){
                res[i+1][j+k] += res[i][j];
                if (res[i+1][j+k] >= P)
                    res[i+1][j+k] -= P;
            }

     forn(i, tst){
        solve();
     }
    

    return 0;
}