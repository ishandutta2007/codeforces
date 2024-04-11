#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int M = 100000;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        ll b[200002];
        for(int i = M - n; i <= M + n; i++) b[i] = 0;
        ll k = 0;
        for(int i = 0; i < n; i++){
            b[k + M]++;
            if(s[i] == '0') k++;
            else k--;
        }
        if(k == 0){
            if(x >= -n && x <= n && b[x + M] != 0) cout << -1 << endl;
            else cout << 0 << endl;
        }
        else{
            ll ans = 0;
            if(k < 0){
                ll l = (x % abs(k) + abs(k)) % abs(k);
                l -= abs(k) * n;
                for(int i = max(l, x); i <= n; i += abs(k)){
                    if(i < -n) continue;
                    ans += b[i + M];
                }
            }
            else{
                ll l = (x % k + k) % k;
                l += k * n;
                for(int i = min(x, l); i >= -n; i -= k){
                    if(i > n) continue;
                    ans += b[i + M];
                }
            }
            cout << ans << endl;
        }
    }
}