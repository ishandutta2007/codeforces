#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool bal(string s) {
    int bal = 0, mn = 0;
    for(auto &c : s) {
        if(c == '(')
            bal++;
        else
            bal--;
        mn = min(bal, mn);
    }
    if(mn < 0 || bal != 0)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool good = false;
        for(int ms = 0; ms < 8; ms++) {
            string t = s;
            for(auto &c : t) {
                if(c == 'A') c = "()"[(ms >> 2) & 1];
                if(c == 'B') c = "()"[(ms >> 1) & 1];
                if(c == 'C') c = "()"[ms & 1];
            }
            if(bal(t)) {
                good = true;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
}