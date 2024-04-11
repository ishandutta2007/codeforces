#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int a[40], b[40];
int dp[MAXN], swp[MAXN];

bool can(int ch) {
    int ich = ch;
    int ta[40], tb[40], chn[40];
    for(int i = 0; i < 40; i++) {
        ta[i] = a[i];
        tb[i] = b[i];
    }
    for(int bit = 39; bit >= 0; bit--) {
        int bnd = MAXN;
        for(int j = bit; j >= 0; j--)
            bnd = min(bnd, ta[j]);
        chn[bit] = min(bnd, ch);
        ch -= chn[bit];
        for(int j = bit; j >= 0; j--)
            ta[j] -= chn[bit];
    }
    if(ch > 0)
        return false;
    int prf = 0;
    for(int bit = 39; bit >= 0; bit--) {
        prf += chn[bit];
        if(ta[bit] + tb[bit] > prf)
            return false;
        prf -= ta[bit];
        prf -= tb[bit];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll lg = 63 - __builtin_clzll(x);
        if(x == (1LL << lg))
            a[lg]++;
        else
            b[lg]++;
    }
    vector<int> answers;
    for(int cur = 1; cur <= n; cur++)
        if(can(cur))
            answers.push_back(cur);
    if(answers.empty())
        cout << "-1\n";
    else {
        for(auto x : answers)
            cout << x << " ";
        cout << '\n';
    }
}