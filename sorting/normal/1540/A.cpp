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

        vector<int> d(n);
        for(int i = 0; i < n; ++i)
            cin >> d[i];

        sort(d.begin(), d.end());

        long long ans = d.back();
        for(int i = 0; i < n - 1; ++i)
            ans -= (long long)(d[i + 1] - d[i]) * (i + 1) * (n - (i + 1));
        cout << ans << "\n";
    }
}