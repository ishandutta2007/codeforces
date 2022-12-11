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

int n, q;
int v[nmax], c[nmax];
int64 bst[nmax];
pair<int64, int64> b1, b2, nb1, nb2;

inline void update(int64 a, int b){
    bst[b] = max(a, bst[b]);
    if (bst[b] > nb1.fs) {
        if (b != nb1.sc)
            nb2 = nb1;
        nb1 = mp(a, b);
    }else if (bst[b] > nb2.fs && b != nb1.sc) {
        nb2 = mp(a, b);
    }
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

    cin >> n >> q;
    forn(i, n)
        scanf("%d", &v[i]);
    forn(i, n)
        scanf("%d", &c[i]);
    forn(i, q) {
        int64 a, b;
        cin >> a >> b;
        b1 = mp(-1e18, 0);
        b2 = mp(-1e18, 0);
        forn(i, n + 1)
            bst[i] = -1e18;
        forn(j, n) {
            nb1 = b1;
            nb2 = b2;
            update(max(v[j]*b, bst[c[j]] + a * v[j]), c[j]);
            if (b1.sc == c[j])
                update(b2.fs + b * v[j], c[j]);
            else
                update(b1.fs + b * v[j], c[j]);
            b1 = nb1;
            b2 = nb2;
        }
        cout << max(0ll, b1.fs) << endl;
    }
        

    return 0;
}