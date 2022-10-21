#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)5005;

int num[3] = {0, 4, 7};
string s;
map<int, vector<int>> mp;
bool dp[20][10];
int las[20][10], sav[20][10];

void solve() {
    memset(dp, false, sizeof(dp));
    s = "0" + s;
    int n = s.length();
    dp[n-1][0] = true;
    for(int i = n-1; i >= 1; i--) {
        for(const auto &p : mp) {
            int b = ((s[i] - '0') - p.first % 10 + 10) % 10;
            if(dp[i][b]) {
                int a = (p.first + b) / 10;
                dp[i-1][a] = true;
                las[i-1][a] = b;
                sav[i-1][a] = p.first;
            }
        }
    }
    if(!dp[0][s[0]-'0']) cout << "-1" << endl;
    else {
        vector<ll> res(6, 0);
        int cur = s[0] - '0';
        for(int i = 0; i < n - 1; i++) {
            int x = sav[i][cur];
            for(int j = 0; j < 6; j++) {
                res[j] *= 10;
                res[j] += mp[x][j];
            }
            cur = las[i][cur];
        }
        for(int j = 0; j < 6; j++) cout << res[j] << " ";
        cout << endl;
    }
}

int main() {
    for (int mask = 0; mask < 729; ++mask) {
        int j = mask;
        vector<int> V;
        int sum = 0;
        for(int i = 0; i < 6; i++) {
            V.push_back(num[j % 3]);
            sum += num[j % 3];
            j /= 3;
        }
        mp[sum] = V;
    }
    int T;
    cin >> T;
    while(T--) {
        cin >> s;
        solve();
    }
}