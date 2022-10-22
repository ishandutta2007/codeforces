#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool scob = 0, word = 0;
    int cnt1 = 0, cnt2 = 0, now_cnt = 0;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '(') {
            scob = 1;
            word = 0;
            cnt1 = max(cnt1, now_cnt);
            now_cnt = 0;
        } else if (x == ')') {
            scob = 0;
            if (word) {
                cnt2++;
            }
            word = 0;
            cnt1 = max(cnt1, now_cnt);
            now_cnt = 0;
        } else if (x == '_') {
            if (word && scob) {
                cnt2++;
            }
            cnt1 = max(cnt1, now_cnt);
            now_cnt = 0;
            word = 0;
        } else {
            word = 1;
            if (!scob) {
                now_cnt++;
            }
        }
    }
    cnt1 = max(cnt1, now_cnt);
    if (word && scob) {
        cnt2++;
    }
    cout << cnt1 << " " << cnt2 << endl;
}