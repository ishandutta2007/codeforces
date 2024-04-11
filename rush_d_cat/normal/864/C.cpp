#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, f, k;
int main() {
    cin >> a >> b >> f >> k;
    int ans = 0, cur = b;
    for (int i = 1; i <= k; i ++) {
        if (i & 1) {
            if (cur < f) return 0 * printf("-1\n");
            cur -= f;

            if ( i == k && cur < a - f ) cur = b, ans ++;
            else if ( i <  k && cur < 2 * (a - f) ) cur = b, ans ++;
            cur -= (a - f); if (cur < 0) return 0 * printf("-1\n");
        } else {
            if (cur < a - f) return 0 * printf("-1\n");
            cur -= (a - f);

            if (i == k && cur < f) cur = b, ans ++;
            else if (i < k && cur < 2 * f) cur = b, ans ++;
            cur -= f; if (cur < 0) return 0 * printf("-1\n");
        }
    }   
    cout << ans << endl;
}