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
        int n, x;
        string s;
        cin >> n >> x >> s;

        int balance = 0;
        for (char c : s)
            balance += (c == '0' ? 1 : -1);

        int cur = 0, ret = (x == 0);
        for (char c : s) {
            cur += (c == '0' ? 1 : -1);
            if (balance == 0 && cur == x) {
                ret = -1;
                break;
            }
            if (cur == x || (balance != 0 && (x - cur) % balance == 0 && (x > cur && balance > 0 || x < cur && balance < 0)))
                ret++;
        }

        cout << ret << "\n";
    }

    return 0;
}