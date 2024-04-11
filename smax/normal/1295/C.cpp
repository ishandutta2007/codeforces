#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        vector<vector<int>> pos(26);
        for (int i=0; i<s.length(); i++)
            pos[s[i]-'a'].push_back(i);

        bool ok = true;
        int ret = 1, idx = 0;
        vector<int> ptr(26);
        for (char c : t) {
            if (pos[c-'a'].empty()) {
                ok = false;
                break;
            }
            ptr[c-'a'] = lower_bound(pos[c-'a'].begin() + ptr[c-'a'], pos[c-'a'].end(), idx) - pos[c-'a'].begin();
            if (ptr[c-'a'] == pos[c-'a'].size()) {
                ret++;
                ptr.assign(26, 0);
            }
            idx = pos[c-'a'][ptr[c-'a']++];
        }

        cout << (ok ? ret : -1) << "\n";
    }

    return 0;
}