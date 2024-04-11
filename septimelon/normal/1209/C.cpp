#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int t;
    cin >> t;
    for (int qq = 0; qq < t; qq++) {
        int n;
        cin >> n;
        cin >> s;
        vector<int> maxc(n);
        vector<bool> two(n, false);
        maxc[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            maxc[i] = max(maxc[i-1], s[i] - '0');
        }
        int max1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] - '0' >= maxc[i])
                continue;
            max1 = s[i] - '0';
            break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] - '0' == maxc[i]) {
                if (s[i] - '0' < max1)
                    break;
                two[i] = true;
            }
        }
        int last = 0;
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (two[i])
                continue;
            if (s[i] - '0' < last)
                can = false;
            last = s[i] - '0';
        }
        if (!can) {
            cout << "-" << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (two[i])
                cout << "2";
            else
                cout << "1";
        }
        cout << '\n';
    }
    return 0;
}