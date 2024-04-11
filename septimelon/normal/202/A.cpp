#include <bits/stdc++.h>

using namespace std;

bool ispal(const string& s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        ++l;
        --r;
    }
    return true;
}

string s0;
string ans = "a";

void dfss(string curs, int ind) {
    if (ind < s0.size()) {
        dfss(curs + s0[ind], ind + 1);
        dfss(curs, ind + 1);
        return;
    }
    if (ispal(curs)) {
        ans = max(ans, curs);
    }
}

int main()
{
    cin >> s0;
    dfss("", 0);
    cout << ans << '\n';
    return 0;
}