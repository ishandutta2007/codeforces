#include <bits/stdc++.h>

using namespace std;

const int k_Inf = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        vector<int> ans(n + 1, k_Inf);

        for(int i = 0; i < n; ++i){
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        for(int i = 1; i <= n; ++i){
            if(pos[i].empty()) continue;
            int max_diff = 0;
            int pr = -1;

            pos[i].push_back(n);
            for(int x: pos[i]){
                max_diff = max(max_diff, x - pr);
                pr = x;
            }

            ans[max_diff] = min(ans[max_diff], i);
        }

        for(int i = 1; i < n; ++i)
            ans[i + 1] = min(ans[i + 1], ans[i]);

        for(int i = 1; i <= n; ++i)
            cout << (ans[i] == k_Inf ? -1 : ans[i]) << " ";
        cout << "\n";
    }
}