#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n);
        for(auto &x: a)
            cin >> x;

        long long ans = 0;
        for(int i = 0; i < n - 1; ++i)
            ans = max(ans, a[i] * a[i + 1]);
        cout << ans << "\n";
    }
}