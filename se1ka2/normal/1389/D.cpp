#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l2 < l1){
            swap(l1, l2);
            swap(r1, r2);
        }
        if(l2 <= r1){
            if((min(r1, r2) - l2) * n >= k){
                cout << 0 << endl;
            }
            else if((max(r1, r2) - l1) * n >= k){
                cout << k - (min(r1, r2) - l2) * n << endl;
            }
            else{
                cout << ((max(r1, r2) - l1) - (min(r2, r1) - l2)) * n + (k - (max(r1, r2) - l1) * n) * 2 << endl;
            }
            continue;
        }
        ll ans = INF;
        for(int i = 1; i <= n; i++){
            if((r2 - l1) * i >= k){
                ans = min(ans, ((r2 - r1) + (l2 - l1)) * i - ((r2 - l1) * i - k));
            }
            else{
                ans = min(ans, ((r2 - r1) + (l2 - l1)) * i + (k - (r2 - l1) * i) * 2);
            }
        }
        cout << ans << endl;
    }
}