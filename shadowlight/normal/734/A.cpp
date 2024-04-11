#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    if (cnt1 > cnt2) {
        cout << "Anton";
    } else if (cnt2 > cnt1) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }
}