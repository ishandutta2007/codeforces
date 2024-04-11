#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
            b[i]--;
        }
        vector<int> next(N);
        for (int i = 0; i < N; i++) {
            next[a[i]] = b[i];
        }
        vector<bool> seen(N);
        int maxlen = N-1;
        long long ans = 0ll;
        for (int i = 0; i < N; i++) {
            if (!seen[i]) {
                int j = next[i], len = 1;
                while (j != i) {
                    seen[j] = true;
                    j = next[j];
                    len++;
                }
                if (len % 2) {
                    len--;
                }
                ans += (long long) (maxlen - (len / 2) + 1) * len;
                maxlen -= len;
            }
        }
        cout << ans << "\n";
    }
}