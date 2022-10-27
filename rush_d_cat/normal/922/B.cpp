#include <iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    int ans = 0;
    for (int a = 1; a <= n; a ++) {
        for (int b = a; b <= n; b ++) {
            int c = a^b;
            if (a+b>c && c <= n && c>=a && c >= b) ans ++;
        }
    }
    cout << ans << endl;
}