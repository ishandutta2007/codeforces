#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, k, a, b, ret = 0;
    cin >> n >> k >> a >> b;
    
    if (k == 1) {
        cout << (n - 1) * a << endl;
        return 0;
    }
    
    while (n > 1) {
        if (n < k) {
            ret += (n - 1) * a;
            break;
        }
        ret += n % k * a;
        n -= n % k;
        ret += min(b, (n - n / k) * a);
        n /= k;
    }
    
    cout << ret << endl;
    
    return 0;
}