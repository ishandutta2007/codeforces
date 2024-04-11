#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;

long long a[k_N], prefix[k_N];

long long get_sum(int l, int r){
    if(l > r) return 0;
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, d, m;
    cin >> n >> d >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    prefix[0] = a[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    
    int idx = upper_bound(a, a + n, m) - a;
    long long ans = 0;
    for(long long x = 0; x <= n; ++x){
        if(n - x < idx) continue;
        long long l = n - x * (d + 1);
        long long r = n - x * (d + 1) + d;
        if(r < 0) continue;
        
        long long t = min(r, (long long)idx);
        long long curr = get_sum(n - x, n - 1) + get_sum(idx - t, idx - 1);
        ans = max(ans, curr);
    }

    cout << ans << "\n";
}