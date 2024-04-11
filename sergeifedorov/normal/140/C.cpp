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
const int inf = (int)1e9 + 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}


vector<pair<pii, int> > res;
set<pii> e;
map<int, int> h;
int a[100100];
int n;

int main ()
{
    int n;
    cin >> n;
    forn(i, n){
        scanf("%d", &a[i]);
        h[a[i]] ++;
    }
    forn(i, n){
        if (h[a[i]] > 0){
            e.insert(mp(-h[a[i]], a[i]));
            h[a[i]] = -1;
        }
    }
    set<pii> :: iterator a, b, c;
    pii a1, b1, c1;
    while (e.size() > 2){
        a = e.begin();
        b = a;
        c = a;
        b ++;
        c ++;
        c ++;
        res.pb(mp(mp(a -> sc, b -> sc), c -> sc));
        a1 = *a; b1 = *b; c1 = *c;
        e.erase(a1);
        e.erase(b1);
        e.erase(c1);
        a1.fs ++;
        b1.fs ++;
        c1.fs ++;
        if (a1.fs < 0)
            e.insert(a1);
        if (b1.fs < 0)
            e.insert(b1);
        if (c1.fs < 0)
            e.insert(c1);
    }
    cout << res.size() << endl;
    forn (i, res.size()){
         if (res[i].fs.fs < res[i].fs.sc)
            swap(res[i].fs.fs, res[i].fs.sc);
         if (res[i].fs.fs < res[i].sc)
            swap(res[i].fs.fs, res[i].sc);
         if (res[i].fs.sc < res[i].sc)
            swap(res[i].fs.sc, res[i].sc);
        printf("%d %d %d\n", res[i].fs.fs, res[i].fs.sc, res[i].sc);
    }


    return 0;
}