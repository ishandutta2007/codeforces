#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 2000005;

int main() {
    LL cnt1 , cnt2 , x , y , z;
    cin >> cnt1 >> cnt2 >> x >> y;
    z = x / __gcd(x , y) * y;
    LL l = 0 , r = 1LL << 60 , m;
    while (l < r) {
        m = l + r >> 1;
        LL p = m / z;
        LL p2 = m / x - p;
        LL p1 = m / y - p;
        p = m - p - p1 - p2;
        p1 = min(p1 , cnt1);
        p2 = min(p2 , cnt2);
        LL q = min(p , cnt1 - p1);
        p1 += q , p -= q;
        q = min(p , cnt2 - p2);
        p2 += q , p -= q;
        if (p1 == cnt1 && p2 == cnt2)
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}