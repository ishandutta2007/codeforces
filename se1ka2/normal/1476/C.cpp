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
        ll c[100005], a[100005], b[100005];
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        a[n] = b[n] = 0;
        ll ans = 0;
        ll s = abs(a[1] - b[1]);
        for(int i = 1; i < n; i++){
            ans = max(ans, s + c[i] - 1 + 2);
            s = max(s + c[i] - 1 - abs(a[i + 1] - b[i + 1]) + 2, abs(a[i + 1] - b[i + 1]));
            if(a[i + 1] == b[i + 1]) s = 0;
        }
        cout << ans << endl;
    }
}