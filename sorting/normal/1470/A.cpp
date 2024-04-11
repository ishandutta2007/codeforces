#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> k(n);
        for(int i = 0; i < n; ++i){
            cin >> k[i];
            --k[i];
        }
        sort(k.begin(), k.end());

        vector<int> c(m);
        for(int i = 0; i < m; ++i)
            cin >> c[i];
    
        auto check = [&](int mid){
            for(int i = mid; i < n; ++i)
                if(k[i] < i - mid)
                    return false;
            return true;
        };

        int l = 0, r = n;
        while(l != r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }

        ll ans = LLONG_MAX, curr = 0;
        for(int i = 0; i < l; ++i)
            curr += c[k[i]];
        for(int i = l; i < n; ++i)
            curr += c[i - l];
        for(; l <= n; ++l){
            ans = min(ans, curr);
            if(l == n) break;
            curr -= c[n - l - 1];
            curr += c[k[l]];
        }

        cout << ans << "\n";
    }
}