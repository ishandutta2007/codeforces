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

const int nmax = 300300;

int a[nmax];
int64 add[nmax];
int t;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    int n;
    cin >> n;
    a[0] = 0;
    add[0] = 0;
    int m = 1;
    double res = 0;
    forn(i, n) {
        int t;
        scanf("%d", &t);
        if (t == 3) {
            add[m-2] += add[m-1];
            res = res - a[m-1] - add[m-1];
            m--;
        } else
        if (t == 2) {
            scanf("%d", &a[m]);
            add[m] = 0;
            m ++;
            res += a[m-1];
        } else {
            int x, c;
            scanf("%d %d", &x, &c);
            add[x-1] += c;
            res += x * c;
        }
        printf("%0.9lf\n", res / m);
    }

    

    return 0;
}