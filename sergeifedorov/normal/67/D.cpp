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

const int nmax = 1000100;

int a[nmax], b[nmax], c[nmax];
int n, res;
int t[nmax];

void solve(){
    forn(i, n)
        a[i] = n - a[i];

    
    for (int i = 0; i <= n + 5; i++)
        t[i] = inf;
    t[0] = -1;
    for (int i = 0; i < n; i++){
        int l = 0, r = n;
        while (l < r){
            int m = (l + r + 1) / 2;
            if (t[m] >= a[i])
                r = m - 1;
            else
                l = m;
        }
        t[l+1] = min(t[l+1], a[i]);
    }
    res = 0;
    while (t[res] < inf) res++;
    res --;
}

int main ()
{

    cin >> n;
    forn(i, n){
        scanf("%d", &a[i]);
        c[a[i] - 1] = i;
    }
    forn(i, n)
        a[i] = c[i];
    forn(i, n){
        scanf("%d", &b[i]);
        c[b[i]-1] = i;
    }
    forn(i, n)
        b[i] = c[i];

    forn(i, n){
        c[a[i]] = b[i];
    }
    forn(i, n)
        a[i] = c[i];
    solve();
    cout << res << endl;



    return 0;
}