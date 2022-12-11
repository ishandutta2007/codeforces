#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef int64_t ll;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0;  i < s1.length(); ++i) {
        if (s1[i] == 'C') {
            s1[i] = 'B';
        }
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] == 'C') {
            s2[i] = 'B';
        }
    }

    vector<int> b1(s1.length() + 1), b2(s2.length() + 1);
    vector<int> a1(s1.length() + 1), a2(s2.length() + 1);
    for (int i = 1; i < s1.length() + 1; ++i) {
        b1[i] = b1[i - 1] + (s1[i - 1] == 'B');
        a1[i] = (a1[i - 1] + 1) * (s1[i - 1] == 'A');
    }
    for (int i = 1; i < s2.length() + 1; ++i) {
        b2[i] = b2[i - 1] + (s2[i - 1] == 'B');
        a2[i] = (a2[i - 1] + 1) * (s2[i - 1] == 'A');
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int cnt1 = b1[r1] - b1[l1 - 1], cnt2 = b2[r2] - b2[l2 - 1];
        int cnta1 = min(r1 - l1 + 1, a1[r1]), cnta2 = min(r2 - l2 + 1, a2[r2]);
        if (cnta1 < cnta2) {
            cout << 0;
            continue;
        }
        if (cnta1 == cnta2 && (cnt1 == 0 && cnt2 > 0)) {
            cout << 0;
            continue;
        }
        if (cnta1 % 3 != cnta2 % 3 || (cnt1 == 0 && cnt2 > 0)) {
            cnt1 += 2;
        }
        if (cnt1 > cnt2) {
            cout << 0;
            continue;
        }
        if ((cnt2 - cnt1) % 2 != 0) {
            cout << 0;
            continue;
        }
        cout << 1;
    }
    return 0;
}