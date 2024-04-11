#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> cnt(26);
    for(auto c : s)
        cnt[c - 'a']++;
    ll ans = *max_element(cnt.begin(), cnt.end());
    for(int i = 0; i < 26; i++) {
        cnt.assign(26, 0);
        vector<ll> ss(26);
        for(auto c : s) {
            int d = c - 'a';
            if(d == i)
                for(int j = 0; j < 26; j++)
                    ss[j] += cnt[j];
            cnt[d]++;
        }
        ans = max(ans, *max_element(ss.begin(), ss.end()));
    }
    cout << ans << '\n';
}