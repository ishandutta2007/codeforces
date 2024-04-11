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
        ll n, k;
        cin >> n >> k;

        ll start_k = k;

        vector<ll> a(n);
        for(ll &x: a)
            cin >> x;

        check_min(k, n);

        ll sum = 0, ans = 0;
        for(int i = 0; i < k; ++i)
            sum += a[i];
        check_max(ans, sum);

        for(int i = k; i < n; ++i){
            sum += a[i];
            sum -= a[i - k];
            check_max(ans, sum);
        }

        ans += k * (start_k - 1 + start_k - k) / 2;
        cout << ans << "\n";
    }
}