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

const int nmax = 1e7 + 10;

int res[nmax];

int main ()
{
    memset(res, 255, sizeof res);
    res[1] = 1;
    for (int i = 1; i < nmax; i ++)
        if (res[i] == -1){
            res[i] = i;
            for (long long j = 1ll * i * i; j < nmax; j += i)
                if (res[j] == -1)
                    res[j] = i;
        }
    for (int i = 2; i < nmax; i ++)
        if (res[i / res[i]] % res[i] == 0)
            res[i] = res[i / res[i]] / res[i];
        else
            res[i] = res[i / res[i]] * res[i];
    long long a, n, ans = 0;
    cin >> a >> n;
    for (int i = 0; i < n; i ++)
        ans += res[a + i];
    cout << ans << endl;
    

    return 0;
}