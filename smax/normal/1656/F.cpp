#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        
        sort(a.begin(), a.end());
        if ((n - 1) * a[0] + accumulate(a.begin() + 1, a.end(), 0LL) > 0 || (n - 1) * a[n-1] + accumulate(a.begin(), a.end() - 1, 0LL) < 0) {
            cout << "INF\n";
            continue;
        }
        
        auto eval = [&] (int t) -> long long {
            long long ret = a[0] * a[n-1] + t * (a[0] + a[n-1]);
            for (int i=1; i<n-1; i++)
                ret += min(a[i] * a[0] + t * (a[i] + a[0]), a[i] * a[n-1] + t * (a[i] + a[n-1]));
            return ret;
        };
        
        int l = -2e6 - 5, r = 2e6 + 5;
        while (r - l > 3) {
            int m = (l + r) / 2;
            if (eval(m) < eval(m + 1))
                l = m + 1;
            else
                r = m;
        }
        
        long long ret = LLONG_MIN;
        for (int i=l; i<=r; i++)
            ret = max(ret, eval(i));
        cout << ret << "\n";
    }
    
    return 0;
}