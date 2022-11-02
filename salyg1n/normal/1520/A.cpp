#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int T = 0; T < t; ++T) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> a(26, false);
        a[s[0] - 'A'] = true;
        string ans = "YES\n";
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1] && a[s[i] - 'A']) {
                ans = "NO\n";
            }
            a[s[i] - 'A'] = true;
        }
        cout << ans;
    }
    return 0;
}