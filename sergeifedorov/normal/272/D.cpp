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

int n;
int a[nmax], b[nmax];
vector<pii> e;
int64 mod;


int64 calc(vector<int> now) {
    
    int64 res = 1;
    int k = 0;
    forn(i, now.size() - 1)
        if (now[i] == now[i+1])
            k ++;
    forn(i, now.size())
        now[i] = i + 1;
    forn(i, now.size())
        while (k > 0 && now[i] % 2 == 0) {
            now[i] /= 2;
            k --;
        }
    forn(i, now.size())
        res = (res * now[i]) % mod;
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n;
    forn(i, n) {
        cin >> a[i];
        e.pb(mp(a[i], i));
    }
    forn(i, n) {
        cin >> b[i];
        e.pb(mp(b[i], i));
    }
    cin >> mod;
    sort(all(e));
    int64 res = 1;
    forn(i, e.size()) {
        int j = i;
        while (j < e.size() && e[j].fs == e[i].fs) j ++;

        vector<int> now;
        for (int k = i; k < j; k ++) {
            now.pb(e[k].sc);
        }
        res = (res * calc(now)) % mod;
        i = j - 1;
    }
    cout << res % mod << endl;
        

    return 0;
}