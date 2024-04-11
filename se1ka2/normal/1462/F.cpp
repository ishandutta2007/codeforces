#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int x[200005], y[200005];
P p[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            p[i] = P(l, r);
            x[i] = l;
            y[i] = r;
        }
        sort(x, x + n);
        sort(y, y + n);
        int ans = n;
        for(int i = 0; i < n; i++){
            int l = lower_bound(y, y + n, p[i].first) - y;
            int r = x + n - upper_bound(x, x + n, p[i].second);
            ans = min(ans, l + r);
        }
        cout << ans << endl;
    }
}