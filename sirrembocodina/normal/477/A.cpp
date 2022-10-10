#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

ll f(ll a) {
    if (a & 1) {
        return (a * ((a + 1) >> 1)) % mod;
    } else {
        return ((a + 1) * (a >> 1)) % mod;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    ll x = a;
    x *= f(b - 1);
    x %= mod;
    ll y = b;
    y *= f(a);
    y %= mod;
    y *= f(b - 1);
    y %= mod;
    cout << (x + y) % mod;
}