#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

int main() {
    LL l , r;
    cin >> l >> r;
    int res = 0;
    for (LL a = 2 ; a < 63 ; ++ a) {
        for (int j = 0 ; j + 1 < a ; ++ j) {
            LL x = (1LL << a) - 1;
            x &= ~(1LL << j);
            if (l <= x && x <= r) {
                //cout << x << endl;
                ++ res;
            }
        }
    }
    cout << res << endl;
    return 0;
}