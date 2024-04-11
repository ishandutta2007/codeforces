#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, n;
        cin >> a >> b >> n;
        int res = 0;
        while(true) {
            if(a < b)
                swap(a, b);
            if(a > n)
                break;
            b += a;
            res++;
        }
        cout << res << '\n';
    }
}