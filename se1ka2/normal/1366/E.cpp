#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[200005], b[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    ll right[200005];
    ll l[200005], r[200005];
    fill(l, l + m, -1);
    fill(r, r + m, -1);
    for(int i = 0; i < n; i++){
        int d = upper_bound(b, b + m, a[i]) - b - 1;
        if(d < 0){
            cout << 0 << endl;
            return 0;
        }
        right[d] = i;
        if(b[d] == a[i]) r[d] = i;
    }
    for(int i = 0; i < m; i++){
        if(r[i] == -1){
            cout << 0 << endl;
            return 0;
        }
        if(i > 0 && r[i] <= right[i - 1]){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int d = upper_bound(b, b + m, a[i]) - b - 1;
        if(b[d] == a[i] && l[d] == -1) l[d] = i;
    }
    ll ans = 1;
    for(int i = 1; i < m; i++){
        ans = ans * (r[i] - right[i - 1]) % MOD;
    }
    cout << ans << endl;
}