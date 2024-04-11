#include <iostream>
using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    if (m % n != 0) {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    m /= n;
    while (m % 2 == 0) 
    {
        m /= 2;
        cnt++;
    }
    while (m % 3 == 0) {
        m /= 3;
        cnt++;
    }
    if (m != 1) {
        cout << -1;
        return 0;
    }
    cout << cnt << endl;
    return 0;
}