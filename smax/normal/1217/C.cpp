#include <bits/stdc++.h>
using namespace std;

int nxt[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        for (int i=0; i<n; i++) {
            if (s[i] == '1')
                nxt[i] = i;
            else
                nxt[i] = (i > 0 ? nxt[i-1] : -1);
        }

        int ret = 0;
        for (int r=0; r<n; r++) {
            int sum = 0;
            for (int l=r; l>=0 && r-l<18; l--) {
                if (s[l] == '0')
                    continue;
                sum += 1 << (r - l);
                if (sum <= r - (l > 0 ? nxt[l-1] : -1))
                    ret++;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}