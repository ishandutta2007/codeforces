#include <bits/stdc++.h>

using namespace std;

int main() {
    /*int n,k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    */
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    long long s = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        mx = max(a[i], mx);
    }
    
    cout << (s % 2 == 0 && mx * 2 <= s ? "YES" : "NO");
}