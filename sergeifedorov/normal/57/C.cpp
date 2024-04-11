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

const long long mod = 1000000007;

const int nmax = 100100;

long long f[nmax];
long long rev[nmax];
int n;

long long calc(int k){
    long long res = (f[n] * f[n-1]) % mod;
    res = ((((((res * rev[k]) % mod ) * rev[n-k]) % mod) * rev[k-1]) % mod) * rev[n-k];
    res = res % mod;
    return res;
}

long long power(long long x, long long p){
    if (p == 0) return 1;
    if (p == 1) return x;
    if (p & 1)
        return (power(x, p-1) * x) % mod;
    long long now = power(x, p / 2);
    return (now * now) % mod;
}

int main ()
{
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = (f[i-1] * i) % mod;
    for (int i = 0; i <= n; i++)
        rev[i] = power(f[i], mod - 2);
    long long res = 0;
    for (int k = 1; k <= n; k++)
        res += calc(k);
    res = (res * 2 - n + mod) % mod;
    cout << res << endl;
    return 0;
}