#include <bits/stdc++.h>
using namespace std;
int t, n, c[3];
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int res = 0x3c3c3c3c;
        for(int i=0; i<n; ++i) {
            c[0] = c[1] = c[2] = 0;
            for(int j=i; j<n && j<i+9; ++j) {
                ++c[s[j] - 'a'];
                if (i != j && c[0] > max(c[1], c[2])) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        if (res == 0x3c3c3c3c) res = -1;
        cout << res << '\n';
    }
}