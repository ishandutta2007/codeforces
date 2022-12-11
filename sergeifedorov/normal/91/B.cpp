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

const int nmax = 100100;

int n;
int a[nmax];
vector<pii> e;
int res[nmax];

int main ()
{
    cin >> n;
    forn(i, n){
        scanf("%d", &a[i]);
        a[i] --;    
        e.pb(mp(a[i], i));
    }
    int lft = 0;
    sort(all(e));
    for (int i = 0; i < n;){
        int l = i;
        while (i < n && e[i].fs == e[l].fs){
            if (lft > e[i].sc)
                res[e[i].sc] = lft - e[i].sc - 1;
            else
                res[e[i].sc] = -1;
            i++;
        }
        for (int j = l; j < i; j++)
            lft = max(lft, e[j].sc);
    }
    forn(i, n)
        printf("%d ", res[i]);
    cout << endl;

        return 0;
}