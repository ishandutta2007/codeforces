#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    string s = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM1234567890";
    for (int qq = 0; qq < t; ++qq) {
        int r, c, k, R = 0;
        cin >> r >> c >> k;
        vector<string> vs(r);
        for (int i = 0; i < r; ++i) {
            cin >> vs[i];
            for (int j = 0; j < c; ++j) {
                if (vs[i][j] == 'R') {
                    ++R;
                }
            }
        }
        int cm = R / k; /// to one ch
        int sb = R % k; /// big ch
        //cout << cm << " " << sb << " " << '\n';
        int curco = 0;
        int cx = 0;
        int cy = 0;
        int curch = 0;
        for (int i = 0; i < r * c; ++i) {
            if (vs[cy][cx] == 'R') {
                ++curco;
                if ((curco > cm + 1 && curch < sb) || (curco > cm && curch >= sb)) {
                    curco = 1;
                    ++curch;
                }
            }
            vs[cy][cx] = s[curch];
            if (cy % 2 == 0) {
                ++cx;
            } else {
                --cx;
            }
            if (cx < 0) {
                ++cx;
                ++cy;
            } else if (cx >= c) {
                --cx;
                ++cy;
            }
        }
        for (int i = 0; i < r; ++i) {
            cout << vs[i] << '\n';
        }
    }
    return 0;
}