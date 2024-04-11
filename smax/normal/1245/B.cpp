#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        string s;
        cin >> n >> a >> b >> c >> s;

        int wins = 0;
        vector<char> ret;
        for (int i=0; i<n; i++) {
            if (s[i] == 'R' && b > 0) {
                ret.push_back('P');
                b--;
                wins++;
            } else if (s[i] == 'P' && c > 0) {
                ret.push_back('S');
                c--;
                wins++;
            } else if (s[i] == 'S' && a > 0) {
                ret.push_back('R');
                a--;
                wins++;
            } else
                ret.push_back('?');
        }

        if (wins < (n % 2 == 0 ? n / 2 : n / 2 + 1))
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<n; i++) {
                if (ret[i] == '?') {
                    if (a > 0) {
                        cout << 'R';
                        a--;
                    } else if (b > 0) {
                        cout << 'P';
                        b--;
                    } else {
                        cout << 'S';
                        c--;
                    }
                } else
                    cout << ret[i];
            }
            cout << "\n";
        }
    }

    return 0;
}