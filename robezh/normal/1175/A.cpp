#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    int T;
    cin >> T;
    while(T--) {
        ll n, k;
        cin >> n >> k;
        ll res = 0;
        while(n > 0) {
            res += n % k;
            n /= k;
            if(n == 0) break;
            res ++;
        }
        cout << res << endl;
    }
}