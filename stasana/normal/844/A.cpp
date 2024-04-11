#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    if (n < k) {
        cout << "impossible" << endl;
        return 0;
    }
    vector<bool> used(26, false);
    for (int i = 0; i < n; ++i) {
        if (!used[s[i] - 'a']) {
            used[s[i] - 'a'] = true;
            --k;
        }
    }
    cout << max(k, 0);
    return 0;
}