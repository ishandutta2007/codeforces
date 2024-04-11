#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const double EPS = 1e-8;
LL n;
LL x, vx, vy, a, b;

map<LL,LL> mp1;
map<pair<LL,LL>, LL> mp2;

int main() {
    scanf("%lld %lld %lld",&n, &a, &b);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld %lld", &x, &vx, &vy);
        mp1[vx*a-vy] ++;
        mp2[make_pair(vx, vy)] ++;
    }
    LL ans = 0;
    for (auto x: mp1) {
        ans += x.second * x.second;
    }
    for (auto x: mp2) {
        ans -= x.second * x.second;
    }
    cout << ans << endl;
}