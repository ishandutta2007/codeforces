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
        int k;
        string s;
        cin >> k >> s;

        int ret = 0;
        vector<int> level(k);
        for (int i=0; i<k; i++) {
            ret = max(ret, level[i]);
            if (s[i] == 'A' && i < k - 1 && s[i+1] == 'P') {
                s[i+1] = 'A';
                level[i+1] = level[i] + 1;
            }
        }

        cout << ret << "\n";
    }

    return 0;
}