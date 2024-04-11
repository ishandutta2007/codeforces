#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;


int cnt[3100][3100];
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int sn = s.size();
    int tn = t.size();

    for (int i = 0; i < sn; i++) {
        if (i < tn) cnt[i][i] = (s[0] == t[i]);
        else cnt[i][i] = 1;
    }

    for (int d = 0; d < sn-1; d++) {
        for (int i = 0; i+d < sn; i++) {
            int j = i+d;
            
            if (j+1 < sn) {
                if (j+1 >= tn || s[d+1] == t[j+1]) {
                    cnt[i][j+1] = (cnt[i][j+1] + cnt[i][j]) % mod;
                }
            }

            if (i > 0) {
                if (i-1 >= tn || s[d+1] == t[i-1]) {
                    cnt[i-1][j] = (cnt[i-1][j] + cnt[i][j]) % mod;
                }
            }
        }
    }

    int answer = 0;
    for (int i = tn-1; i < sn; i++) {
        answer = (answer + cnt[0][i]) % mod;
    }
    cout << (answer + answer) % mod << endl;

    return 0;
}