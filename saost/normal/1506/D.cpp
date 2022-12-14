#include <iostream>
#include <algorithm>
using namespace std;
long long t, n, a[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        int sl = 1, d=1;
        for(int i=2; i<=n; i++) {
            if (a[i] == a[i-1]) ++d;
            else sl = max(sl, d), d = 1;
        }
        sl = max(sl, d);
        cout << max(n%2, 2*sl - n) << '\n';
    }
}