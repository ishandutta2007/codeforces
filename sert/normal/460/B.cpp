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

ll sumc(ll a) {
    ll ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

ll a, b, c, x;
vector <ll> ans;

int main() {
    //freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> a >> b >> c;
    for (ll sum = 1; sum < 300; sum++) {
        x = b * st(sum, a) + c;
        if (sumc(x) == sum && x < 1000000000)
            ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}