    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int mx = -1, sum = accumulate(v.begin(), v.end(), 0);
        for(int b = 0; b < k; b++) {
            int ans = sum;
            for(int i = b; i < n; i += k)
                ans -= v[i];
            mx = max(mx, abs(ans));
        }
        cout << mx << endl;
    }