#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int cnt = 0;
    for (int p = 0; p < 50; ++p) {
        string t = "";
        for (int j = 0; j < p; ++j) {
            t += "00";
        }
        t += "1";
        while (s.size() < t.size()) {
            s += "0";
        }
        while (t.size() < s.size()) {
            t += "0";
        }
        bool f = false;
        for (int i = (int)t.size() - 1; i > -1; i--) {
            if (s[i] < t[i]) {
                break;
            }
            if (s[i] > t[i]) {
                f = true;
                break;
            }
        }
        if (f) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}