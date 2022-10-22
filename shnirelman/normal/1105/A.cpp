#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    int ans = 0, res = 1e9;
    for(int i = 1; i <= 100; i++) {
        int cur = 0;
        for(auto a1 : a) {
            int b = abs(a1 - i);
            cur += max(b - 1, 0);
        }
        
        if(cur < res) {
            ans = i;
            res = cur;
        }
    }
    
    cout << ans << ' ' << res;
}