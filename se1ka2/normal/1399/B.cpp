#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[52], b[52];
        ll la = INF, lb = INF;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            la = min(la, a[i]);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            lb = min(lb, b[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) ans += max(a[i] - la, b[i] - lb);
        cout << ans << endl;
    }
}