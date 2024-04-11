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
        int n;
        cin >> n;

        set<int> ret;
        for (int i=1; i<=sqrt(n); i++) {
            ret.insert(i);
            ret.insert(n / i);
        }
        ret.insert(0);

        cout << ret.size() << "\n";
        for (int i : ret)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}