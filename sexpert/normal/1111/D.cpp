#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
int pdp[60][50050], sdp[60][50050];

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

const ll MAXN = 1e5 + 5;
ll fac[MAXN], ifac[MAXN];

void add(int &a, int b) {
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(int i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (ifac[i] * i) % MOD;

    string s;
    cin >> s;
    int n = s.size() / 2;
    map<int, int> to;
    for(int i = 'a'; i <= 'z'; i++)
        to[i] = i - 'a';
    for(int i = 'A'; i <= 'Z'; i++)
        to[i] = i - 'A' + 26;

    vector<int> cnt(52);
    for(auto c : s)
        cnt[to[c]]++;
    ll base = (2LL * fac[n] * fac[n]) % MOD;
    for(auto x : cnt)
        base = (base * ifac[x]) % MOD;
    if(*max_element(cnt.begin(), cnt.end()) > n) {
        int q;
        cin >> q;
        while(q--) {
            int x, y;
            cin >> x >> y;
            cout << "0\n";
        }
        return 0;
    }

    vector<vector<int>> ans(52, vector<int>(52));
    for(int ch = 0; ch < 52; ch++) {
        if(!cnt[ch])
            continue;
        memset(pdp, 0, sizeof pdp);
        pdp[0][0] = 1;
        for(int i = 1; i <= 52; i++) {
            for(int s = n; s >= 0; s--)
                pdp[i][s] = pdp[i - 1][s];
            if(i == ch + 1)
                continue;
            if(!cnt[i - 1])
                continue;
            for(int s = n; s >= cnt[i - 1]; s--)
                add(pdp[i][s], pdp[i - 1][s - cnt[i - 1]]);
        }
        memset(sdp, 0, sizeof sdp);
        sdp[53][0] = 1;
        for(int i = 52; i >= 1; i--) {
            for(int s = n; s >= 0; s--)
                sdp[i][s] = sdp[i + 1][s];
            if(i == ch + 1)
                continue;
            if(!cnt[i - 1])
                continue;
            for(int s = n; s >= cnt[i - 1]; s--)
                add(sdp[i][s], sdp[i + 1][s - cnt[i - 1]]);
        }
        for(int i = 1; i <= 52; i++) {
            if(i == ch + 1) {
                ans[ch][i - 1] = pdp[52][n - cnt[ch]];
                continue;
            }
            if(!cnt[i - 1])
                continue;
            if(cnt[ch] + cnt[i - 1] > n)
                continue;
            int ta = n - cnt[ch] - cnt[i - 1];
            ll res = 0;
            for(int x = 0; x <= ta; x++)
                res = (res + (ll)pdp[i - 1][x] * sdp[i + 1][ta - x]) % MOD;
            ans[ch][i - 1] = res;
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << (base * ans[to[s[l]]][to[s[r]]]) % MOD << '\n';
    }
}