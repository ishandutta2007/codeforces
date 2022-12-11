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

const int nmax = 1000100;

int n, m;
int a[nmax];
int us[nmax];
vector<pii> now;

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    
    cin >> n;
    forn(i, n)
        scanf("%d", &a[i]);
    cin >> m;
    forn(i, m) {
        int x;
        scanf("%d", &x);
        x --;
        us[x] = 1;

    }
    ford(i, n) {
        if (now.size() == 0 || us[i] || now.back().fs != a[i]) {
            now.pb(mp(a[i], i));
            a[i] *= -1;
            continue;
        }
        now.pop_back();
    }
    if (now.size() != 0) {
        puts("NO");
    } else {
        puts("YES");
        forn(i, n)
            printf("%d ", a[i]);
        puts("");
    }


    return 0;
}