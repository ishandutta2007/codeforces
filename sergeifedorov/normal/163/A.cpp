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

const long long mod = 1e9 + 7;

const int nmax = 5100;

int n, m;
string s, t;
int dp[nmax][nmax];
long long res;

int main ()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();
    forn(i, n)
        dp[i][0] = 1;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= m; j ++){
            dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
            if (i < n && j < m && s[i] == t[j])
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
            }
    for (int i = 0; i <= n; i ++)
        res = (res + dp[i][m]) %  mod;      
    cout << (res - n + mod) % mod << endl;

    

    return 0;
}