#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n + 2);
    s[0] = "#################################################################################################";
    s[n + 1] = s[0];
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    vector<int> i1{1, 1, 1, 2};
    vector<int> i2{-1, 0, 1, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] == '.') {
                for (int k = 0; k < 4; ++k) {
                    if (s[i + i1[k]][j + i2[k]] == '#') {
                        cout << "NO\n";
                        return 0;
                    } else {
                        s[i + i1[k]][j + i2[k]] = '#';
                    }
                }
            }
        }
    }
    cout << "YES\n";

    return 0;
}