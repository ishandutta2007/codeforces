#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)1e6 + 34;

int solve(string s, char ch) {
    int b = 0;
    int r = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        ch = (ch == 'r' ? 'b' : 'r');
        if (s[i] == ch) if (i % 2) b++; else r++;
    }
    return max(r, b);
}

int main() {
    int n, r = 0, b = 0;
    init();
    map <string, int> m;
    m["monday"] = 0;
    m["tuesday"] = 1;
    m["wednesday"] = 2;
    m["thursday"] = 3;
    m["friday"] = 4;
    m["saturday"] = 5;
    m["sunday"] = 6;
    string s1, s2;
    int res;
    cin >> s1 >> s2;
    res = (m[s2] - m[s1] + 7) % 7;
    if (res == 0 || res == 2 || res == 3) cout << "YES"; else cout << "NO";



    return 0;
}