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

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        long long ans = 0;
        vector<pair<int, int>> nums;
        nums.push_back({a[n - 1], 1});

        for(int i = n - 2; i >= 0; --i){
            int cnt = 1;
            if(!nums.empty() && nums.back().first < a[i]){
                ans += a[i] -  nums.back().first;
                while(!nums.empty() && nums.back().first < a[i]){
                    cnt += nums.back().second;
                    nums.pop_back();
                }
            }
            nums.push_back({a[i], cnt});
        }

        cout << ans << "\n";
    }
}