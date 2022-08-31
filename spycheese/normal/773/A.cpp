#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h> 
#include <list>
#include <cstring>
#include <queue>
using namespace std;

#define name "problem5"
#define times clock() * 1.0 / CLOCKS_PER_SEC

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

struct __isoff {
    __isoff() {
        if(_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        //ios_bsume::sync_with_stdio(0);
        //srand(time(0));
        srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
    }
    ~__isoff() {
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 131;
const ull p2 = 129;
const double eps = 1e-8;
const double pi = acos(-1.0);

const int infi = 2e9 + 7;
const ll inf = 1e18 + 7;
const ll dd = 5e5 + 7;

typedef long long ll;
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, a, n) for(int i = a; i < n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

ll gcd(ll a, ll b) {
    while(a != 0 && b != 0) {
        a %= b;
        swap(a, b);
    }
    return a + b;
}

ll solve(ll a, ll b, ll p, ll q) {
    ll g = gcd(p, q);
    p /= g;
    q /= g;

    if(p == 0 && a > 0) {
        return -1;
    }

    if(p == q && a != b) {
        return -1;
    }

    ll l = -1, r = infi;
    while(r - l > 1) {
        ll s = (l + r) / 2;
        if(p * s - a >= 0 && (q - p) * s - b + a >= 0) {
            r = s;
        }
        else {
            l = s;
        }
    }

    return q * r - b;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << '\n';
    }

}