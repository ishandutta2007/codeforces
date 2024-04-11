#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int t;
LL n, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        LL res = 0;
        while(n) {
            res = res + n - (n / k) * k;
            n = (n / k) * k;
            if (n) res ++;
            n = n / k; 
        }
        cout << res << endl;
    }
}