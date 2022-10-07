#include <iostream>

using namespace std;

bool go() {
    int state = 0;
    string s;
    cin >> s;
    string ans;
    string cur;
    bool found = false;
    for(int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '@') {
            found = true;
            if (state != 0 || cur.size() == 0) {
                return false;
            } else {
                cur += c;
                state = 1;
            }
        } else {
            cur += c;
            if (state == 1) {
                ans += cur;
                ans += ",";
                cur = "";
                state = 0;
            }
        }
    }
    if (state != 0 || !found) {
        return false;
    }
    ans = ans.substr(0, ans.size() - 1);
    ans += cur;
    cout << ans << endl;
}

int main() {
    if (!go()) {
        cout << "No solution" << endl;
    }
    return 0;
}