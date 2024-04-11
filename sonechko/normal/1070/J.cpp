#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200100;
const int SZ = 30100;

int n, m, k;

bitset<N> dp;
bitset<SZ> dp2;

void solve(){
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector <pair<int, char> > vec;
    map<char, int> mp1;
    for (int i = 0; i < s.size(); i++){
        ++mp1[s[i]];
    }
    for (auto it = mp1.begin(); it != mp1.end(); it++){
        vec.push_back({it->second, it->first});
    }
    dp.reset();
    dp[0] = 1;
    for (int j = 0; j < vec.size(); j++){
        dp |= (dp<<vec[j].first);
    }
    for (int i = n; i <= k; i++){
        if (dp[i] == 1 && (k-i) >= m){
            cout << "0\n";
            return;
        }
    }
    ll ans = 1e15;
    for (int i = 0; i < vec.size(); i++){
        dp2.reset();
        dp2[0] = 1;
        for (int j = 0; j < vec.size(); j++){
            if (j == i)
                continue;
            dp2 |= (dp2 << vec[j].first);
        }
        for (int j = 0; j <= n; j++){
            if (dp2[j] == 1 && (k-vec[i].first-j) <= m){
                ans = min(ans, (n-j)*1ll*(m-(k-vec[i].first-j)));
            }
        }
        for (int j = 0; j <= m; j++){
            if (dp2[j] == 1 && (k-vec[i].first-j) <= n){
                ans = min(ans, (m-j)*1ll*(n-(k-vec[i].first-j)));
            }
        }
    }
    cout << ans << "\n";


}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }

}

/**

*/