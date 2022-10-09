#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

#define int long long

int32_t main() {
    int k;
    cin >> k;
    string s = "";
    for (int i = 1; ; i++) {
        string t = "";
        int n = i;
        while (n) {
            t.push_back('0' + n % 10);
            n /= 10;
        }
        reverse(t.begin(), t.end());
        s += t;
        if (s.size() >= k) {
            cout << s[k - 1] << endl;
            return 0;
        }
    }
}