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

        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        int sum = 0;
        for(int i = 1; i <= n; ++i)
            sum += a[i];

        if(sum % n){
            cout << "-1\n";
            continue;
        }
        sum /= n;

        vector<array<int, 3>> ans;

        for(int i = 2; i <= n; ++i){
            if(a[i] % i){
                ans.push_back({1, i, i - a[i] % i});
                a[i] += i - a[i] % i;
                a[1] -= i - a[i] % i;
            }

            ans.push_back({i, 1, a[i] / i});
            a[1] += a[i];
            a[i] = 0;
        }

        for(int i = 2; i <= n; ++i)
            ans.push_back({1, i, sum});

        cout << ans.size() << "\n";
        for(auto [i, j, x]: ans)
            cout << i << " " << j << " " << x << "\n";
    }
}