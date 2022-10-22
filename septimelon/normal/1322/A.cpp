#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    int co = 0, cz = 0;
    int ans = 0;
    bool fix = false;
    for (int i = 0; i < s.size(); ++i) {
        if (fix) {
            if (s[i] == '(') {
                ++co;
                if (co == cz) {
                    ans += co + cz;
                    co = 0;
                    cz = 0;
                    fix = false;
                }
            } else {
                ++cz;
            }
        } else {
            if (s[i] == '(') {
                ++co;
            } else {
                if (co > 0) {
                    --co;
                } else {
                    ++cz;
                    fix = true;
                }
            }
        }
    }
    if (co + cz > 0) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";
    
    return 0;
}