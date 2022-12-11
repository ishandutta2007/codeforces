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
    string s;
    cin >> n >> s;
    cout << min(solve(s, 'r'), solve(s, 'b'));



    return 0;
}