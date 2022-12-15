#include <bits/stdc++.h>

using namespace std;

const int k_N = 2000 + 3;

int n;
int p[2 * k_N];

bool dp[2 * k_N][k_N];
vector<int> groups;

void solve(){
    cin >> n;
    for(int i = 0; i < 2 * n; ++i)
        cin >> p[i];

    groups.clear();
    set<pair<int, int>> s;
    for(int i = 0; i < 2 * n; ++i)
        s.insert({p[i], i});

    int r = 2 * n - 1;
    while(!s.empty()){
        auto t = s.rbegin();
        int idx = t->second;
        int cnt = r - idx + 1;

        for(int i = idx; i <= r; ++i)
            s.erase({p[i], i});
        groups.push_back(cnt);

        r = idx - 1;
    }

    for(int i = groups.size() - 1; i >= 0; --i){
        for(int j = 0; j <= n; ++j){
            dp[i][j] = 0;
            if(i == groups.size() - 1){
                dp[i][j] = (j == 0 || j == groups[i]);
                continue;
            }

            dp[i][j] = dp[i + 1][j];
            if(dp[i][j]) continue;

            if(j >= groups[i])
                dp[i][j] = dp[i + 1][j - groups[i]];
        }
    }

    cout << (dp[0][n] ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}