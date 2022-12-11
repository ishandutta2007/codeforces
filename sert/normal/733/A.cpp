#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;


int main() {
    init();

    string s;
    cin >> s;
    s.push_back('A');
    int lst = -1;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'U' || s[i] == 'I' || s[i] == 'Y') {
            ans = max(ans, i - lst);
            lst = i;
        }
    }
    cout << ans;

    return 0;
}