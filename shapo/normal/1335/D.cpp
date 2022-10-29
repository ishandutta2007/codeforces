#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        string s;
        for (int i = 0; i < 9; ++i) {
            cin >> s;
            // Replace all '1's to '2's
            for (char& c : s) {
                if (c == '1') {
                    c = '2';
                }
            }
            /* In our case it is equivalent to
             *
             * for (int idx = 0; idx < int(s.size()); ++idx) {
             *     char& c = s[idx];
             *     if (c == '1') {
             *         c = '2';
             *     }
             * }
             *
             */
            cout << s << '\n';
        }
    }
    return 0;
}