#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, a[100000], dp[100000];
    unordered_map<int, int> mp;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=n-1; i>=0; i--) {
        mp.insert({a[i], 1});
        dp[i] = mp.size();
    }
    for (int i=0; i<m; i++) {
        int l;
        cin >> l;
        cout << dp[l-1] << endl;
    }
    
    return 0;
}