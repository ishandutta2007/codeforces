#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

const long long N = 1e6 + 34;
const long long inf = 1e9 + 34;

long long n, x, y, mxx, mxy, mnx, mny;

int main() {
    //freopen("a.in", "r", stdin);
    mxx = mxy = -inf;
    mnx = mny = inf;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        mxx = max(mxx, x);
        mnx = min(mnx, x);
        mxy = max(mxy, y);
        mny = min(mny, y);
    }
    mxx = max(mxx - mnx, mxy - mny);
    cout << mxx * mxx;
}