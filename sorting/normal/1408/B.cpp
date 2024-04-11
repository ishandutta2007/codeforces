#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        if(k == 1){
            if(a[0] != a[n - 1]){
                cout << "-1\n";
                continue;
            }

            cout << "1\n";
            continue;
        }

        int cnt = 0;
        for(int i = 0; i < n - 1; ++i)
            if(a[i + 1] != a[i])
                cnt++;

        if(cnt == 0){
            cout << "1\n";
            continue;
        }

        cout << cnt / (k - 1) + (bool)(cnt % (k - 1)) << "\n";
    }
}