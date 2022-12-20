#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = 0;
        for(int i = 0; i < n - 1; ++i){
            int big = max(a[i], a[i + 1]);
            int small = min(a[i], a[i + 1]);
            while(big > 2 * small){
                ans++;
                small *= 2;
            }
        }

        cout << ans << "\n";
    }
}