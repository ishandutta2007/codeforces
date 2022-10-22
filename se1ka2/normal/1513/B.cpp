#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        int x = (1 << 30) - 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            x &= a[i];
        }
        int c = n;
        for(int i = 0; i < n; i++){
            if(a[i] == x) c--;
        }
        ll ans = 1;
        for(int i = n - 2; i > n - 2 - c; i--) ans = ans * i % MOD;
        for(int i = n - c; i > 0; i--) ans = ans * i % MOD;
        cout << ans << endl;
    }
}