#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n > 0) {
        ans++;
        n--;
        if (ans % m == 0) n++;
    }
    cout << ans << endl;
    return 0;
}