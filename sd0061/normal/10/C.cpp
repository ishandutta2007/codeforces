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
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 1000005;
int cnt[10] , n;

void work() {
    int i , j , k;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i) {
        ++ cnt[(i - 1) % 9 + 1];
    }
    LL ans = 0;
    for (i = 1 ; i <= 9 ; ++ i)
        for (j = 1 ; j <= 9 ; ++ j) {
            k = (i * j - 1) % 9 + 1;
            ans += (LL) cnt[i] * cnt[j] * cnt[k];
        }
    for (i = 1 ; i <= n ; ++ i)
        ans -= n / i;
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}