#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(26, 1000);
    char ch;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (a[ch - 'a'] == 1000) {
            a[ch - 'a'] = 1;
            ++cnt;
        } else {
            ++a[ch - 'a'];
        }
    }
    if (n <= k) {
        cout << "YES";
        return 0;
    }
    sort(a.begin(), a.end());
    int qwer = 0;
    for (int i = 0; i < 26; ++i) {
        if (a[i] == 1000) {
            break;
        }
        int qwe = a[i] - qwer;
        qwer += qwe;
        n -= (qwe * cnt);
        k -= qwe;
        --cnt;
        if (k < 0) {
            cout << "NO";
            return 0;
        }
        if (n <= k) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}