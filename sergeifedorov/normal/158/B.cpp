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


int n;
int c[10];
int a[100100];

int main ()
{
     cin >> n;
     forn(i, n){
        scanf("%d", &a[i]);
        c[a[i]] ++;
     }
     int res = c[4];
     {
        int now = min(c[1], c[3]);
        res += now;
        c[1] -= now;
        c[3] -= now;
     }
     {
        int now = c[3];
        res += now;
        c[3] -= now;
     }
     {
        int now = c[2] / 2;
        res += now;
        c[2] -= now;
        c[2] -= now;
     }
     if (c[2] > 0){
        res ++;
        c[2] --;
        c[1] -= 2;
     }
     res += (c[1] + 3) / 4;
     cout << res << endl;

    return 0;
}