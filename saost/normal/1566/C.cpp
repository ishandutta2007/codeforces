#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, m, res, a[N], f[N];
string s, s2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s >> s2;
        int res = 0, tmp = 0;
        for(int i=0; i<s.length(); ++i) {
            if (s[i] != s2[i]) {
                res += 2;
                tmp = 0;
            }
            else if (s[i] == '1') {
                if (tmp < 0) ++res;
                tmp = min(tmp + 1, 1);
            }
            else {
                if (tmp > 0) ++res;
                tmp = max(tmp - 1, -1);
                ++res;
            }
        }
        cout << res << '\n';
    }
}