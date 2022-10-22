#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll ans = 1;
        for(int i = 0; i < k; i++) ans = ans * n % MOD;
        cout << ans << endl;
    }
}