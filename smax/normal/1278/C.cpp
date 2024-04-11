#include <bits/stdc++.h>
using namespace std;

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int balance = 0, sum = 0;
        unordered_map<int, int> pref{{0, 0}};
        for (int i=0; i<2*n; i++) {
            cin >> a[i];
            balance += (a[i] == 1 ? 1 : -1);
            if (i >= n) {
                sum += (a[i] == 1 ? 1 : -1);
                if (!pref.count(sum))
                    pref[sum] = i - n + 1;
            }
        }

        int ret = (pref.count(balance) ? pref[balance] : INT_MAX);
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            sum += (a[i] == 1 ? 1 : -1);
            if (pref.count(balance - sum))
                ret = min(ret, pref[balance - sum] + n - i);
        }

        cout << ret << "\n";
    }

    return 0;
}