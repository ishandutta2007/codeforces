#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> sk(n);
    fro (int i = 0; i < n; i++) cin >> sk[i];
    vector<vector<int>> B(n, {0});
    for (int i = 0; i < n; i++) {
        for (auto p : sk[i]) {
            B[i].pb(B[i].back() + (p=='(') - (p==')'));
        }
    }
    map<int, int> frs, sec;
    int z = 0;
    for (auto p : B) {
        int mim = 0;
        for (auto pp : p) {
            mim = min(mim, pp);
        }
        if (mim == 0) {
            frs[p.back()]++;
            if (p.back() == 0) z++;
        } else if (mim >= p.back()) {
            sec[-p.back()]++;
        }
    }
    int ans = 0;
    for (auto i : frs) {
        ans += frs[i.first] * sec[i.first];
    }
    cout << ans+z*z;

}