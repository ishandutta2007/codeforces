#include <bits/stdc++.h>

using namespace std;

char c;
string ans;
int T, n, p;
vector<int> pos;

bool query(string str) {
    cout << "? " << str << endl;
    int k; cin >> k; pos.resize(k);
    for (int i = 0; i < k; i++) { cin >> pos[i]; pos[i]--; }
    for (auto u : pos) {
        for (int i = 0; i < str.size(); i++) { ans[u + i] = str[i]; }
    } return !pos.empty();
}

int main() {
    for (cin >> T; T; T--) {
        cin >> n; ans.clear(); ans.resize(p = n);
        query("CH"); query("HC"); query("CO"); query("HO");
        for (int i = 0; i < n; i++) {
            if (ans[i]) { p = i; }
        }
        if (p == n) {
            if (query("OOO")) {
                c = query("OOOC") ? 'C' : 'H';
            } else if (query('O' + string(n - 2, 'C'))) {
                if (pos[0]) { ans[0] = 'O'; } else { ans[n - 1] = 'C'; }
            } else if (query('O' + string(n - 2, 'H'))) {
                if (pos[0]) { ans[0] = 'O'; } else { ans[n - 1] = 'H'; }
            } else {
                c = query("CCCC") ? 'C' : 'H';
            }
        } else {
            for (int i = p; i >= 0; i--) {
                if (ans[i]) { continue; }
                query(ans[i + 1] + ans.substr(i + 1, p - i));
                ans[i] = ans[i] ? ans[i] : 'O';
                if (ans[i]) { cerr << i << endl; }
            }
            for (int i = p + 1; i < n; i++) {
                if (!query(ans.substr(0, i) + ans[i - 1])) {
                    c = query(ans.substr(0, i) + 'C') ? 'C' : 'H'; break;
                }
            }
        }
        for (int i = 0; i < n; i++) { ans[i] = ans[i] ? ans[i] : c; }
        cout << "! " << ans << endl;
        int ok; cin >> ok; assert(ok);
    }
    return 0;
}