#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] <= c){
            ans++;
        }
    }
    cout << ans << endl;

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}