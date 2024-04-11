#include <iostream>

using namespace std;

int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    int k1 = n % 5, k2 = m % 5;
    for (int i = 0; i < 5; i++) {
        long long a1 = n / 5, a2 = m / 5;
        if (i != 0 && i <= k1) a1++;
        if (i != 0 && 5 - i <= k2) a2++;
        ans += a1 * a2;
        //cout << a1 << " " << a2 << endl;
    }
    cout << ans;
}