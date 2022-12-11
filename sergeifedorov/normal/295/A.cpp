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

const int nmax = 100100;

int n, m, k;
int a[nmax], l[nmax], r[nmax], d[nmax];

int64 cnt[nmax], w[nmax];


int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n >> m >> k;
    forn(i, n)
        scanf("%d", &a[i]);
    forn(i, m) {
        scanf("%d %d %d", &l[i], &r[i], &d[i]);
        l[i] --;
        r[i] --;
    }
    forn(i, k) {
        int l, r;
        scanf("%d %d", &l, &r);
        l --; r--;
        cnt[l] ++;
        cnt[r+1] --;
    }
    {
        int64 now = 0;
        forn(i, m) {
            now += cnt[i];
            w[l[i]] += now * d[i];
            w[r[i]+1] -= now * d[i];
        }
    }

    {
        int64 now = 0;
        forn(i, n) {
            now += w[i];
            cout << now + a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}