#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll d[100005];
        for(int i = 0; i < n; i++) cin >> d[i];
        sort(d, d + n, greater<ll>());
        ll ans = d[0];
        ll s = 0;
        for(int i = 1; i < n; i++){
            s += (d[i - 1] - d[i]) * i;
            ans -= s;
        }
        cout << ans << endl;
    }
}