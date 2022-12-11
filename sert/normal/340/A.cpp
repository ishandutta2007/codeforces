#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>

#define mp make_pair
#define pb push_back
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e6 + 5;

ll x, y, a, b;

ll gcd(ll aa, ll bb) {
    ll cc = aa % bb;
    while (cc != 0) {
        aa = bb;
        bb = cc;
        cc = aa % bb;
    }
    return bb;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    ll h = x * y / gcd(x, y);
    ll pos = ((a + h - 1) / h) * h;
    cout << (b - pos + h) / h;
    //cout << n;
    return 0;
}