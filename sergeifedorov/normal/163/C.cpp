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

const int nmax = 300300;

int n;
long double l , v1, v2;
long double res[nmax], a[nmax];

int main ()
{
    cin >> n >> l >> v1 >> v2;
    forn(i, n) {
         int x;
        scanf("%d", &x);
        a[i] = x;
        a[n + i] = x + 2. * l;
    }
    a[2 * n] = 1e10;

    long double len = 1.0 * v2 * l / (v1 + v2);
    vector<long double> st;
    forn(i, n * 2){
        st.pb(a[i]);
        st.pb(a[i] + len);
        st.pb(a[i] - len);
    }
    st.pb(0);
    st.pb(len);
    st.pb(2 * l - len);
    forn(i, st.size()){
        while (st[i] < 0)
            st[i] += 2 * l;
        while (st[i] >= 2 * l)
            st[i] -= 2 * l;
    }
    sort(all(st));
    int m = 1;
    for (int i = 1; i < st.size(); i ++)
        if (st[i] - st[m-1] > 1e-10){
            st[m] = st[i];
            m ++;
        }
    st.resize(m);
    st.pb(2. * l);
    int p1, p2;
    p1 = 0;
    p2 = -1;
    forn(i, st.size()-1){   
        long double mid = (st[i] + st[i+1]) / 2.;
        while (a[p1] < mid)
            p1 ++;
        p2 = max(p2, p1-1);
        while (a[p2 + 1] - mid < len)
            p2 ++;
        res[p2-p1 + 1] += st[i+1] - st[i];
    }
    forn(i, n + 1)
        printf("%0.15lf\n", (double)(res[i] / (2. * l)));

    return 0;
}