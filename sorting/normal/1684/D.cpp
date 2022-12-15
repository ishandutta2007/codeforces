#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            b[i] = -a[i] + (n - 1 - i);
        }
        sort(all(b));
        ll ans = 0;
        for(int i = 0; i < n; ++i)
            ans += a[i];
        for(int i = 0; i < k; ++i)
            ans += b[i];
        ans -= (ll)k * (ll)(k - 1) / 2;
        cout << ans << "\n";
    }
}