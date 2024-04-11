#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <char> ans(n);
    int pos1, pos2;
    if (n % 2) {
        char x;
        cin >> x;
        n--;
        ans[n / 2] = x;
        pos1 = n / 2 - 1;
        pos2 = n / 2 + 1;
    } else {
        pos1 = n / 2 - 1;
        pos2 = n / 2;
    }
    //cout << pos1 << " " << pos2 << endl;
    for (int i = 0; i < n / 2; i++) {
        char x1, x2;
        cin >> x1 >> x2;
        ans[pos1 - i] = x1;
        ans[pos2 + i] = x2;
        //cout << ans[pos1 - i] << " " << ans[pos2 + i] << endl;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
}