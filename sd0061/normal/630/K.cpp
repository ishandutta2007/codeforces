#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;

int main() {
    LL n , res = 0;
    cin >> n;
    for (int i = 0 ; i < 1 << 9 ; ++ i) {
        LL x = 1;
        for (int j = 0 ; j < 9 ; ++ j)
            if (i >> j & 1)
                x = x / __gcd(x , (LL)j + 2) * (j + 2);
        if (__builtin_popcount(i) & 1)
            res -= n / x;
        else
            res += n / x;
    }
    cout << res << endl;
    return 0;
}