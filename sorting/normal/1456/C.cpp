#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5 + 3;

ll c[N], n, k, dp[N], suffix[N];
multiset<ll> ms;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c, c + n);

    suffix[n] = 0;
    for(int i = n - 1; i >= 0; --i)
        suffix[i] = suffix[i + 1] + c[i];

    dp[n] = 0;
    ms.insert(dp[n] + suffix[n]);
    for(int i = n - 1; i >= 0; --i){
        dp[i] = *ms.rbegin();
        ms.insert(dp[i] + suffix[i]);
        if(ms.size() > k + 1)
            ms.erase(ms.find(dp[i + k + 1] + suffix[i + k + 1]));
    }

    cout << dp[0] << "\n";
}