#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

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
const string task = "c";

template <class T> T sqr (T x) {return x * x;}

int n;
int a[100010];
int st[100010], sum, s[100010];

void answer (int64 res)
{
    cout << res << endl;
    exit (0);
}

int main ()
{
//  freopen ((task + ".in").data(), "r", stdin);
//  freopen ((task + ".out").data(), "w", stdout);
    scanf ("%d", &n);
    seta (a, 0);
    seta (st, 0);
    for (int i = 1; i <= n; i ++)
        scanf ("%d", &a[i]);
    sum = 0;
    forn (i, n)
        sum += a[i+1];
    if (sum % 3)
        answer (0);
    sum /= 3;

    for (int i = n; i >= 1; i --)
        st[i] = st[i+1] + a[i];
    for (int i = 1; i <= n; i ++)
        if (st[i] == sum)
            st[i] = 1;
        else
            st[i] = 0;
    for (int i = n; i >= 1; i --)
        st[i] = st[i] + st[i+1];

    seta (s, 0);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + a[i];
    for (int i = 1; i <= n; i ++)
        if (s[i] == sum)
            s[i] = 1;
        else
            s[i] = 0;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + s[i];
    int64 res = 0;
    for (int i = 1; i <= n; i ++)
        if (s[i] > s[i-1])
            res += st[i+2];
    answer (res);       
    return 0;
}