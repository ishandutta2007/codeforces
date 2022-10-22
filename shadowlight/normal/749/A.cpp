#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> ans;
    if (n >= 3 && n % 2) {
        ans.push_back(3);
        n -= 3;
    }
    for (int i = 0; i < n / 2; i++) {
        ans.push_back(2);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}