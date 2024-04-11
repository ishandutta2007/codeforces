#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size(), l, r, ans = 0;
    for (int i = 0; i < n; i++) {
        l = r = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') {
                l++;
                r++;
            }
            else if (s[j] == ')') {
                l--;
                r--;
            }
            else {
                l--;
                r++;
            }
            if (r < 0)
                break;
            l = max(l, 0);
            if (l <= 0 && r >= 0 && r % 2 == 0)
                ans++;
        }
    }
    cout << ans;
}