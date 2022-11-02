#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int B = 10, L = 70, K = 1<<10;

ll dp[B][L][K], ep[B][L][K];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int b = 1; b < B; b ++) {
        dp[b][0][0] = 1;
        for(int i = 1; i < L; i ++) for(int j = 0; j < K; j ++)
            for(int d = 0; d <= b; d ++) dp[b][i][j] += dp[b][i-1][j^(1<<d)];
        for(int d = 1; d <= b; d ++) ep[b][1][1<<d] = 1;
        for(int i = 2; i < L; i ++) for(int j = 0; j < K; j ++)
            for(int d = 0; d <= b; d ++) ep[b][i][j] += ep[b][i-1][j^(1<<d)];
        for(int j = 0; j < K; j ++) for(int i = 1; i < L; i ++) ep[b][i][j] += ep[b][i-1][j];
    }
    auto calc = [&](int b, ll x) {
        vector <int> d;
        while(x) d.push_back(x%b), x/=b;
        ll ans = 0;
        for(int i = d.size()-1, mask = 0; i >= 0; i --) {
            for(int j = 0; j < d[i]; j ++) {
                if(i == d.size()-1 && j == 0) ans += ep[b-1][i][0];
                else ans += dp[b-1][i][mask^(1<<j)];
            }
            mask ^= 1 << d[i];
        }
        return ans;
    };
    int q;
    cin >> q;
    while(q --) {
        int b;
        ll l, r;
        cin >> b >> l >> r;
        cout << calc(b, r+1) - calc(b, l) << endl;
    }
}