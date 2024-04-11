#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int c, sum;
        cin >> c >> sum;

        int di = sum / c, rm = sum % c, ret = 0;
        for (int i=0; i<c; i++) {
            ret += (di + (rm > 0)) * (di + (rm > 0));
            rm--;
        }

        cout << ret << "\n";
    }

    return 0;
}