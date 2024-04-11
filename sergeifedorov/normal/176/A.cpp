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

const int nmax = 1000;

int a[nmax][nmax], b[nmax][nmax], c[nmax][nmax];


int main ()
{
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, n){
        string s;
        cin >> s;
        forn(j, m)
            cin >> a[i][j] >> b[i][j] >> c[i][j];
    }

    int res = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if (i != j){
                vector<int> now;
                forn(k, m)
                    forn(l, c[i][k])
                        now.pb(b[j][k] - a[i][k]);
                sort(all(now));
                reverse(all(now));
                int cnt =0 ;
                forn(w, now.size()){
                    if (w >= k) break;
                    cnt += now[w];
                    res = max(res, cnt);
                }
            }
    cout << res << endl;
            


    

    return 0;
}