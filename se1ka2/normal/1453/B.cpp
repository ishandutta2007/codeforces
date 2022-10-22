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
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) ans += abs(a[i + 1] - a[i]);
        ll s = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
        for(int i = 1; i < n - 1; i++){
            if((a[i] > a[i - 1]) == (a[i] > a[i + 1])){
                s = max(s, min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1])) * 2);
            }
        }
        cout << ans - s << endl;
    }
}