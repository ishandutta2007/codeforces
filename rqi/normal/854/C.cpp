#include <bits/stdc++.h>

using namespace std;

long long ans[300001];
long long costs[300001];
int main() {
       ios_base::sync_with_stdio(false);
    long long ans1 = 0;
    long long n, k;
    cin >> n >> k;
    set<pair<long long, long long>> v;
    for(int i = 1; i <= k; i++){
        long long x;
        cin >> x;
        costs[i] = x;
        v.insert(make_pair(x, i));
    }
        
    for(int i = k+1; i < n+1; i++){
        long long x;
        cin >> x;
      	costs[i] = x;
        v.insert(make_pair(x, i));
        auto it = *prev(v.end());
        ans[it.second] = i;
        v.erase(it);
    }
    for(int i = n+1; i < n+k+1; i++){
        auto it = *prev(v.end());
        ans[it.second] = i;
        v.erase(it);
    }
    for(int i = 1; i < n+1; i++){
        ans1+=(ans[i] - i) * costs[i];
    }
    cout << ans1 << '\n';
    for(int i = 1; i < n+1; i++){
        cout << ans[i] << ' ';
    }
}