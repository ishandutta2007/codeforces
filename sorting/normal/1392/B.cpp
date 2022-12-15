#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int mx = a[0], mn = a[0];
        for(int i = 0; i < n; ++i){
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }

        if(k & 1){
            for(int i = 0; i < n; ++i)
                cout << mx - a[i] << " ";
            cout << "\n";
        }
        else{
            for(int i = 0; i < n; ++i)
                cout << a[i] - mn << " ";
            cout << "\n";
        }
    }
}