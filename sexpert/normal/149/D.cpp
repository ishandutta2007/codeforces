#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;

const int MAX = 1005;
int mch[1005];
ll mem[MAX][MAX][3][3];

ll dp(int l, int r, int bs, int be) {
    //cout << l << " " << r << " " << bs << " " << be << endl;
    if(l == r + 1)
        return 1;
    if(mem[l][r][bs][be] != -1)
        return mem[l][r][bs][be];
    int mi = mch[l];
    // take first
    ll res = 0;
    if(mi != r) {
        if(bs != 1)
            res = (res + dp(l + 1, mi - 1, 1, 0) * dp(mi + 1, r, 0, be)) % MOD;
        if(bs != 2)
            res = (res + dp(l + 1, mi - 1, 2, 0) * dp(mi + 1, r, 0, be)) % MOD;
    }
    else {
        if(bs != 1)
            res = (res + dp(l + 1, mi - 1, 1, 0)) % MOD;
        if(bs != 2)
            res = (res + dp(l + 1, mi - 1, 2, 0)) % MOD;
    }
    // take last
    if(mi != r) {
        res = (res + dp(l + 1, mi - 1, 0, 1) * dp(mi + 1, r, 1, be)) % MOD;
        res = (res + dp(l + 1, mi - 1, 0, 2) * dp(mi + 1, r, 2, be)) % MOD;
    }
    else {
        if(be != 1)
            res = (res + dp(l + 1, mi - 1, 0, 1)) % MOD;
        if(be != 2)
            res = (res + dp(l + 1, mi - 1, 0, 2)) % MOD;
    }
    return mem[l][r][bs][be] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == ')') {
            int x = st.back(); st.pop_back();
            mch[x] = i; mch[i] = x;
        }
        else
            st.push_back(i);
    }
    //for(int i = 0; i < n; i++)
    //    cout << i << " " << mch[i] << '\n';

    memset(mem, -1, sizeof mem);
    cout << dp(0, n - 1, 0, 0) << '\n';
}