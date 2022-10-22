#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char a = 'r';
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == a) {
                cnt1++;
            } else {
                cnt3++;
            }
        } else {
            if (s[i] == a) {
                cnt4++;
            } else {
                cnt2++;
            }
        }
    }
    int ans1 = min(cnt1, cnt2) + abs(cnt1 - cnt2);
    int ans2 = min(cnt3, cnt4) + abs(cnt3 - cnt4);
    cout << min(ans1, ans2);
}