#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000009;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        k = (k + 1) % 2 + 1;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < k; i++){
            ll l = -INF;
            for(int j = 0; j < n; j++) l = max(l, a[j]);
            for(int j = 0; j < n; j++) a[j] = l - a[j];
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}