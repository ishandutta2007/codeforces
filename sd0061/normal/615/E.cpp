#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 2105;
const int Q = 1e9 + 7;

int main() {
    LL n;
    cin >> n;
    if (n == 0) {
        puts("0 0");
        return 0;
    }
    int l = 1 , r = 1e9 , m;
    while (l < r) {
        m = l + r >> 1;
        if ((LL)3 * m * (m + 1) >= n) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    LL K = r;
    -- r;
    n -= (LL)3 * r * (r + 1);
    int x = K + K - 1 , y = 2;
    -- n;

    LL d;
    d = min(n , K - 1);
    n -= d;
    x += -1 * d , y += 2 * d;

    d = min(n , K);
    n -= d;
    x += -2 * d , y += 0 * d;

    d = min(n , K);
    n -= d;
    x += -1 * d , y += -2 * d;
 
    d = min(n , K);
    n -= d;
    x += 1 * d , y += -2 * d;

    d = min(n , K);
    n -= d;
    x += 2 * d , y += 0 * d;
    
    d = min(n , K);
    n -= d;
    x += 1 * d , y += 2 * d;

    printf("%d %d\n" , x , y);
    return 0;
}