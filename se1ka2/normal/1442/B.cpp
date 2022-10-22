#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[200005], b[200005];
        int r[200005], p[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            r[a[i]] = i;
        }
        for(int i = 0; i < n; i++) p[i] = -1;
        for(int i = 0; i < k; i++){
            cin >> b[i];
            b[i]--;
            b[i] = r[b[i]];
            p[b[i]] = i;
        }
        ll ans = 1;
        for(int i = 0; i < k; i++){
            int s = 0;
            if(b[i] > 0 && p[b[i] - 1] < i) s++;
            if(b[i] < n - 1 && p[b[i] + 1] < i) s++;
            ans = (ans * s) % MOD;
        }
        cout << ans << endl;
    }
}