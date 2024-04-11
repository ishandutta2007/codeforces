#include <bits/stdc++.h>

using namespace std;

char inv(char c) {
    if (c == 'W') {
        return 'B';
    }
    return 'W';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] != s[i - 1]) {
            ans.push_back(i + 1);
            s[i] = inv(s[i]);
            s[i + 1] = inv(s[i + 1]);
        }
    }
    if (s[n - 1] != s[n - 2]) {
        if (n % 2 == 0) {
            cout << "-1\n";
            return 0;
        } else {
            for (int i = 1; i < n - 1; i += 2) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}