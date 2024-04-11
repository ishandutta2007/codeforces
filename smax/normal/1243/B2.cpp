#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    while (k--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        bool solExists = true;
        vector<pair<int, int>> ret;
        for (int i=0; i<n; i++)
            if (s[i] != t[i]) {
                int j = i + 1;
                while (j < n && s[i] != s[j] && s[i] != t[j])
                    j++;
                if (j == n) {
                    solExists = false;
                    break;
                }
                if (s[i] == s[j]) {
                    swap(s[j], t[i]);
                    ret.push_back(make_pair(j, i));
                } else {
                    swap(s[j], t[j]);
                    swap(s[j], t[i]);
                    ret.push_back(make_pair(j, j));
                    ret.push_back(make_pair(j, i));
                }
            }

        if (solExists) {
            cout << "Yes\n" << ret.size() << "\n";
            for (auto p : ret)
                cout << p.first + 1 << " " << p.second + 1 << "\n";
        } else
            cout << "No\n";
    }

    return 0;
}