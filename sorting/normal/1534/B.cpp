#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n + 2);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        ll ans = 0, cnt = 0;
        for(int i = 1; i <= n; ++i){
            int mx = 0;
            check_max(mx, a[i - 1]);
            check_max(mx, a[i + 1]);
            if(a[i] > mx){
                ans += a[i] - mx;
                a[i] = mx;
            }
        }

        for(int i = 1; i <= n; ++i){
            if(a[i] >= a[i - 1]) ans += a[i] - a[i - 1];
            if(a[i] >= a[i + 1]) ans += a[i] - a[i + 1];
        }

        cout << ans << "\n";
    }
}