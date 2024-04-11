#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int mink = 1e9 + 7;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        mink = min(mink, r - l + 1);
    }
    int now = 0;
    cout << mink << endl;
    for (int i = 0; i < n; i++) {
        if (now == mink) {
            now = 0;
        }
        cout << now << " ";
        now++;
    }
    //system("pause");
}