#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        long long a, b, c, sum, mn, k;
        cin >> a >> b >> c;
        sum = a + b + c;
        mn = min(a, min(b, c));
        k = sum / 9;
        cout << ((sum == k * 9 && mn >= k) ? "YES" : "NO") << "\n";
    }

    return 0;
}