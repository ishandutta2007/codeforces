#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 3;

int n;
pair<int, int> p[N];
multiset<int> ms;
ll dp[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    for(int i = 0; i < n; ++i)
        ms.insert(p[i].first + p[i].second);
    dp[n - 1] = 0;

    for(int i = n - 2; i >= 0; --i){
        ms.erase(ms.find(p[i + 1].first + p[i + 1].second));
        int idx = upper_bound(p, p + n, pair{*ms.rbegin(), INT_MAX}) - p - 1;
        if(idx == i) dp[i] = dp[i + 1] + p[i + 1].first - *ms.rbegin();
        else dp[i] = dp[idx];
    }
    for(int i = 0; i < n; ++i)
        dp[0] += p[i].second;
    cout << dp[0] << "\n";
}