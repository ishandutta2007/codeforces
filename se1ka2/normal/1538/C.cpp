#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += upper_bound(a, a + n, r - a[i]) - lower_bound(a, a + n, l - a[i]);
        }
        for(int i = 0; i < n; i++){
            if(a[i] * 2 >= l && a[i] * 2 <= r) ans--;
        }
        cout << ans / 2 << endl;
    }
}