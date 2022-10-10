#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s.substr(i, m) == t) {
            ans++;
            i += m - 1;
        }
    }
    cout << ans << endl;
}