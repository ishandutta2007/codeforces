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

        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        for(int i = 0; i < n; ++i) cin >> c[i];

        vector<int> ans(n);
        ans[0] = a[0];

        for(int i = 1; i < n - 1; ++i){
            if(a[i] == ans[i - 1])
                ans[i] = b[i];
            else
                ans[i] = a[i];
        }

        if(a[n - 1] != ans[n - 2] && a[n - 1] != ans[0]) ans[n - 1] = a[n - 1];
        else if(b[n - 1] != ans[n - 2] && b[n - 1] != ans[0]) ans[n - 1] = b[n - 1];
        else if(c[n - 1] != ans[n - 2] && c[n - 1] != ans[0]) ans[n - 1] = c[n - 1];

        for(int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
}