#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector <int> ans;
    while (b > a) {
        ans.push_back(b);
        if (b % 2 == 0) {
            b /= 2;
        } else if (b % 10 != 1) {
            cout << "NO";
            return 0;
        } else {
            b /= 10;
        }
    }
    if (b != a) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    cout << ans.size() + 1 << endl;
    cout << a << " ";
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}