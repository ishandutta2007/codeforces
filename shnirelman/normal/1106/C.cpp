#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(a.begin(), a.end());
    
    long long ans = 0;
    if(n % 2) {
        long long s = a[0] + a[1] + a[2];
        ans += s * s;
        for(int i = 0; i + 3 < n - i; i++) {
            s = a[i + 3] + a[n - i - 1];
            ans += s * s;
        }
            
    } else {
        for(int i = 0; i < n / 2; i++) {
            long long s = a[i] + a[n - i - 1];
            ans += s * s;
        }
    }
    
    cout << ans;
}