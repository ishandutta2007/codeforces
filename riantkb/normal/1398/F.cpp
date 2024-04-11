#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> lef(n + 1, vector<int>(2, M)), rig(n + 1, vector<int>(2, -1));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' || s[i] == '?') lef[i + 1][0] = min(lef[i][0], i);
        if (s[i] == '1' || s[i] == '?') lef[i + 1][1] = min(lef[i][1], i);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0' || s[i] == '?') rig[i][0] = max(rig[i + 1][0], i);
        if (s[i] == '1' || s[i] == '?') rig[i][1] = max(rig[i + 1][1], i);
    }
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0, l = 0; j < n; j += i) {
            int mi = M;
            for (int k = 0; k < 2; ++k) {
                int le = max(lef[j + 1][k], l);
                int ri = rig[j][k];
                if (ri - le + 1 >= i) {
                    mi = min(mi, le + i);
                }
            }
            if (mi < M) {
                ++ans;
                l = mi;
            }
        }
        cout << ans << (i < n ? ' ' : '\n');
    }
    return 0;
}