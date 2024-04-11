#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mn = a[0];
    for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i]);
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mn) {
            ++cnt1;
        }
        if (a[i] == mn + 1) {
            ++cnt2;
        }
        if (a[i] == mn + 2) {
            ++cnt3;
        }
    }
    if (cnt1 == 0 || cnt3 == 0) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        return 0;
    }
    cout << n - max(min(cnt1, cnt3) * 2, cnt2 - cnt2 % 2) << endl;
    if (min(cnt1, cnt3) * 2 > cnt2 - cnt2 % 2) {
        if (cnt1 > cnt3) {
            for (int i = 0; i < cnt1 - cnt3; ++i) {
                cout << mn << " ";
            }
        } else {
            for (int i = 0; i < cnt3 - cnt1; ++i) {
                cout << mn + 2 << " ";
            }
        }
        for (int i = 0; i < min(cnt1, cnt3) * 2 + cnt2; ++i) {
            cout << mn + 1 << " ";
        }
    } else {
        for (int i = 0; i < cnt2 / 2; ++i) {
            cout << mn << " "<< mn + 2 << " ";
        }
        if (cnt2 % 2 == 1) {
            cout << mn + 1 << " ";
        }
        for (int i = 0; i < cnt1; ++i) {
            cout << mn << " ";
        }
        for (int i = 0; i < cnt3; ++i) {
            cout << mn + 2 << " ";
        }
    }
    return 0;
}