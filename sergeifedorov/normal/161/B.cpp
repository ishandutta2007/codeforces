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
        
const int nmax = 1500;

int k, n;
vector<pii> tab, kar, res[nmax];
int got[nmax];

int main ()
{
    cin >> n >> k;
    forn(i, n){
        int x, t;
        scanf("%d %d", &x, &t);
        if (t == 1)
            tab.pb(mp(x, i));
        else
            kar.pb(mp(x, i));
    }
    sort(tab.rbegin(), tab.rend());
    int m = 0;
    forn(i, tab.size()){
        if (m < k){
            res[m].pb(tab[i]);
            got[m] = 1;
            m ++;
        } else {
            res[k-1].pb(tab[i]);
            got[k-1] = 1;
            m = k;
        }
    }
    forn(i, kar.size()){
        if (m < k){
            res[m].pb(kar[i]);
            m ++;
        } else {
            res[k-1].pb(kar[i]);
        }
    }
    double rs = 0.0;
    forn(i, k){
        long long sum = 0, mn = 1e18;
        forn(j, res[i].size()){
            sum += res[i][j].fs;
            mn = min(mn, 1ll * res[i][j].fs);
        }   
        if (got[i]){
            rs = rs + sum - mn / 2.;
        } else
            rs = rs + sum;
    }
    printf("%0.1lf\n", rs);
    forn(i, k){
        printf("%d ", res[i].size());
        forn(j, res[i].size()){
            printf("%d", res[i][j].sc + 1);
            if (j + 1 < res[i].size())
                printf(" ");
            else
                puts("");
        }
    }
        
    

    return 0;
}