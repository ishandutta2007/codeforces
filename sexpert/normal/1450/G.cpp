#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1 << 20;
bitset<MAX> dpgl, mv, dp[20];
map<char, int> to;
char rv[20];
int cnt[20], le[20], ri[20], n, A, B, b;

void solve(int ms) {
    int L = 1e9, R = -1, tot = 0;
    vector<int> tr, chr, oth;
    for(int i = 0; i < b; i++) {
        if(ms & (1 << i)) {
            L = min(L, le[i]);
            R = max(R, ri[i]);
            tot += cnt[i];
            chr.push_back(i);
            if(dp[i][ms ^ (1 << i)])
                dp[i][ms] = dpgl[ms] = 1;
        }
        else
            oth.push_back(i);
    }

    if(tot >= ((R - L + 1) * A + B - 1) / B)
        mv[ms] = 1;

    if(oth.empty())
        return;

    sort(chr.begin(), chr.end(), [&](int a, int b){ return le[a] < le[b]; });
    int cms = 0;
    for(auto c : chr) {
        cms |= (1 << c);
        if(mv[cms] && dpgl[cms] && dp[oth[0]][ms ^ cms]) {
            for(auto tc : oth)
                dp[tc][ms] = 1;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> A >> B;
    string s;
    cin >> s;

    for(auto &c : s) {
        if(!to.count(c)) {
            rv[b] = c;
            to[c] = b++;
        }
    }

    for(int i = 0; i < s.size(); i++) {
        cnt[to[s[i]]]++;
        ri[to[s[i]]] = i;
    }
    for(int i = s.size() - 1; i >= 0; i--)
        le[to[s[i]]] = i;

    dpgl[0] = mv[0] = 1;
    for(int i = 0; i < b; i++) {
        dp[i][0] = dp[i][1 << i] = 1;
        dpgl[1 << i] = 1;
    }

    for(int i = 1; i < (1 << b); i++)
        solve(i);

    vector<char> ans;

    for(int i = 0; i < b; i++)
        if(dp[i][(1 << b) - 1])
            ans.push_back(rv[i]);

    sort(ans.begin(), ans.end());

    cout << ans.size();
    for(auto &c : ans)
        cout << " " << c;
    cout << '\n';

    /*for(int i = 0; i < (1 << b); i++) {
        for(int j = 0; j < b; j++)
            cout << bitset<4>(i) << " " << j << " " << dp[j][i] << '\n';
    }

    cout << '\n';*/
}