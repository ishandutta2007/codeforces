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

int solve(long long a, long long b){
    long long w = (b / a) % (a + 1);
    return (w + 1) % 2 ;
}

int calc(long long a, long long b){
    if (a > b) swap(a, b);
    if (a == 0) return 0;
    if (!calc(b % a, a))
        return 1;
    if (solve(a, b - b % a))
        return 1;
    return 0;
}

void solve(){
    long long a, b;
    cin >> a >> b;
    if (calc(a, b))
        puts("First");
    else
        puts("Second"); 
}

long long gen(){
    long long mod = 1e18;
    long long now = rand();
    now = (now << 48 | rand());
    now = (now % mod + mod) % mod;
    return now;
}

int main ()
{
    int tst;
    cin >> tst;
    forn(i, tst){
        solve();
    }   

    return 0;
}