#include <iostream>
using namespace std;
typedef long long LL;
LL n, k;
LL min(LL x, LL y) {return x < y ? x :y;}
int main() {
    cin >> n >> k;
    LL t = 1;
    while (t <= n) t *= 2L;

    t /= 2;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    
    LL ans = 0;
    for (int i = 1; i <= 100; i ++) {
        ans += t; t >>= 1;
    }
    cout << ans << endl;
}