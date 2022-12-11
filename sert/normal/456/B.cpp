#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>

#define ff first
#define ss second
#define y1 yy1

using namespace std;

typedef long long ll;
const ll N = 1e6 + 7;

ll st(ll a, ll s) {
    ll res = 1;
    for (int i = 0; i < s; i++)
        res *= a;
    return res;
}

string s;
ll ans, x;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> s;
    s = '0' + s;
    x = ((s[s.length() - 2] - '0') * 10 + s[s.length() - 1] - '0') % 4;

    ans = st(1ll, x) + st(2ll, x) + st(3ll, x) + st(4ll, x);
    cout << ans % 5;

    return 0;
}