#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(n % 2050){
            cout << "-1\n";
            continue;
        }
        ll x = n / 2050;
        ll ans = 0;
        while(x){
            ans += x % 10;
            x /= 10;
        }
        cout << ans << "\n";
    }
}