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

const int64 mod = 1000000007;
const int64 nmax = 1e6 + 1e5;

int64 dp[nmax];


void pre_calc() {
    dp[0] = 1;
    forn(i, nmax) {
            if (i == 0)
                continue;
            dp[i] += dp[i-1];
            if (i >= 2) 
                dp[i] += dp[i-2] * (i - 1) % mod;
            dp[i] %= mod;
        }
}

int64 calc(int a, int b) {
    int64 res = dp[a];
    forn(i, b)
        res = res * (a + b - i) % mod;
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    pre_calc();
    int n, a, b;
    a = b = 0;
    cin >> n;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (x == 1)
            a ++;
        else
            b ++;
    }   
    cout << calc(a, b) << endl;

    return 0;
}