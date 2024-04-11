#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> s(n + 1), cnt(n + 1, 0);
        for(int i = 0; i < n; ++i)
            cin >> s[i];

        ll ans = 0;
        for(int i = 0; i < n; ++i){
            ans -= min(s[i] - 1, cnt[i]);
            ans += max(0, s[i] - (n - i));
            for(int j = min(s[i], n - i); j > 1; --j){
                ++ans;
                if(i + j < n) cnt[i + j]++;
            }
            if(i != n - 1) cnt[i + 1] += max(0, cnt[i] - (s[i] - 1));
        }

        cout << ans << "\n";
    }
}