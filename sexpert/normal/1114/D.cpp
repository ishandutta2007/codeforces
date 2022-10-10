    #include <bits/stdc++.h>
    using namespace std;
     
    vector<int> v;
    int memo[5005][5005];
     
    int dp(int l, int r) {
        if(l == r)
            return 0;
        if(memo[l][r] != -1)
            return memo[l][r];
        if(v[l] == v[r])
            return memo[l][r] = dp(l + 1, r - 1) + 1;
        return memo[l][r] = 1 + min(dp(l + 1, r), dp(l, r - 1));
    }
     
    int main() {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(v.empty() || x != v.back())
                v.push_back(x);
        }
        int m = v.size();
        memset(memo, -1, sizeof memo);
        cout << dp(0, m - 1) << endl;
    }