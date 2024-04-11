#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != a[0])
            ans = max(ans, i);
        if(a[i] != a[n - 1])
            ans = max(ans, n - i - 1);
    }
        
    cout << ans;
        
}