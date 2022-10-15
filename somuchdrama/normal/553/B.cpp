#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    --k;
    ll fib[n];
    fib[1] = fib[2] = fib[0] = 1;
    for(int i = 3; i < n; ++i) fib[i] = fib[i - 1] + fib[i - 2];
    ll sum[n];
    sum[0] = 1;
    for(int i = 1; i < n; ++i) sum[i] = sum[i - 1] + fib[i];
    bool ans[n];
    for(int i = 0; i < n; ++i){
        ans[i] = 0;
        if(k >= sum[n - i - 1]){
            ans[i] = 1;
            k -= sum[n - i - 1];
        }
    }
    int res[n];
    for(int i = 0; i < n; ++i) res[i] = i + 1;
    for(int i = 1; i < n; ++i){
        if(ans[i]) swap(res[i], res[i - 1]);
    }
    for(int i = 0; i < n; ++i) cout << res[i] << ' ';
    return 0;
}